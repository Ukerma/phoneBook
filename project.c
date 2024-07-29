#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ad[25], soyad[25], numara[20];
    int menu;
    int kisiBulundu = 0;

    do // Menü ekranını yazdırıyoruz
    {
        printf("\t╔═════════════════════╗\n");
        printf("\t║                     ║\n");
        printf("\t║  -MENU-             ║\n");
        printf("\t║   1-Numara Ekle     ║\n");
        printf("\t║   2-Numara Sil      ║\n");
        printf("\t║   3-Kisi Listesi    ║\n");
        printf("\t║   4-Kisi Duzenle    ║\n");
        printf("\t║   5-Cikis           ║\n");
        printf("\t║                     ║\n");
        printf("\t║                     ║\n");
        printf("\t║                     ║\n");
        printf("\t║                     ║\n");
        printf("\t║                     ║\n");
        printf("\t║                     ║\n");
        printf("\t╠═════════════════════╣\n");
        printf("\t║  ╔═══╗   ■   ╔═¤═╗  ║\n");
        printf("\t╚═════════════════════╝\n");

        printf("\n» Lutfen yapmak istediginiz islemi seciniz: ");
        scanf("%d", &menu);

        do // Geçersiz girişler için tekrar kontrol
        {
            if (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5)
            {
                printf("» Gecersiz giris yaptiniz. Lutfen yapmak istediginiz islemi seciniz:");
                scanf("%d", &menu);
            }
        } while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5);

        switch (menu)
        {
        case 1:
        { // Numara ekleme işlemi
            FILE *fp = fopen("kisi_listesi.txt", "a");
            rewind(fp);
            if (fp == NULL)
            {
                printf("\n» Rehber Acilamadi Tekrar Deneyiniz!");
            }
            else
            {
                printf("\n» Rehber Acildi Kisi Kayit Islemine Baslayabilirsiniz!\n\n");
                printf("╔═══════════════════════════╣ Numara Ekleme ╠════════════════════════════");
            }
            printf("\n║ » Ad:");
            scanf("%s", ad);
            printf("║ » Soyad:");
            scanf("%s", soyad);
            printf("║ » Numara:");
            scanf("%s", numara);
            printf("╚════════════════════════════════════════════════════════════════════════\n");
            // Yeni kişiyi dosyaya ekliyoruz
            fprintf(fp, "║ » %-18s ║ » %-20s ║ » %-18s ║\n", ad, soyad, numara);
            printf("\n » Kisi ekleme islemi basarili...\n\n");
            fclose(fp);
        }
        break;
        case 2:
        { // Numara silme işlemi
            printf("\n» Rehber Acildi Kisi Silme Islemine Baslayabilirsiniz.\n\n");
            FILE *fp = fopen("kisi_listesi.txt", "r");
            rewind(fp);

            char c;
            if (fp == NULL)
            {
                printf("\n» Rehber Acilamadi Tekrar Deneyiniz!");
            }
            else
            { // Kişi listesi görüntüleniyor
                printf("╔══════════════════════╦════╣ Kisi Listesi ╠════╦══════════════════════╗\n");
                printf("║ %-20s ║ %-22s ║ %-20s ║\n", "Ad", "Soyad", "Numara");
                c = fgetc(fp);
                printf("╠══════════════════════╬════════════════════════╬══════════════════════╣\n");
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fp);
                }
                printf("╚══════════════════════╩════════════════════════╩══════════════════════╝\n\n");
            }

            fclose(fp);

            do
            {
                char silinecekIsim[25];
                FILE *fp = fopen("kisi_listesi.txt", "r");
                rewind(fp);
                // Silinecek kişinin ismini alıyoruz
                printf("╔═══════════════════════════╣ Numara Silme ╠════════════════════════════\n");
                printf("║ » Silmek istediginiz kisinin ismini giriniz: ");
                scanf("%s", silinecekIsim);
                printf("╚═══════════════════════════════════════════════════════════════════════\n");

                char line[2000];
                int lineCount = 0, foundCount = 0;
                char foundLines[100][2000]; // Max 100 matching entries
                // Dosyayı tarayıp eşleşen kayıtları buluyoruz
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    lineCount++;
                    char *namePosition = strstr(line, silinecekIsim);
                    if (namePosition != NULL && strncasecmp(namePosition, silinecekIsim, strlen(silinecekIsim)) == 0)
                    {
                        strcpy(foundLines[foundCount++], line);
                    }
                }
                fclose(fp);

                if (foundCount == 0)
                {
                    printf("\n» Kisi bulunamadi. Lutfen gecerli bir isim giriniz.\n\n");
                }
                else
                { // Bulunan kişileri listeliyoruz
                    printf("╔═══╦══════════════════════╦══╣ Bulunan Kisiler ╠═══╦══════════════════════╗\n");
                    for (int i = 0; i < foundCount; i++)
                    {
                        printf("║ %d %s", i + 1, foundLines[i]);
                    }
                    printf("╚══════════════════════════╩════════════════════════╩══════════════════════╝\n");
                    int secim;
                    printf("» Silmek istediginiz kisiyi seciniz (1-%d): ", foundCount);
                    scanf("%d", &secim);

                    if (secim < 1 || secim > foundCount)
                    {
                        printf("\n» Gecersiz secim.\n");
                    }
                    else
                    {
                        FILE *fp = fopen("kisi_listesi.txt", "r");
                        FILE *fs = fopen("gecici_dosya.txt", "w");
                        rewind(fp);

                        int currentLine = 0;
                        while (fgets(line, sizeof(line), fp) != NULL)
                        {
                            currentLine++;
                            if (currentLine != lineCount - foundCount + secim)
                            {
                                fprintf(fs, "%s", line);
                            }
                            else
                            {
                                kisiBulundu = 1;
                            }
                        }

                        fclose(fp);
                        fclose(fs);

                        if (kisiBulundu == 0)
                        {
                            printf("\n» Kisi silme islemi basarisiz.\n");
                            remove("gecici_dosya.txt");
                        }
                        else
                        {
                            printf("\n» Kisi silme islemi basarili...\n\n");
                            remove("kisi_listesi.txt");
                            rename("gecici_dosya.txt", "kisi_listesi.txt");
                        }
                    }
                }
            } while (kisiBulundu == 0);
        }
        break;
        case 3:
        { // Kişi listesini görüntüleme
            FILE *fp = fopen("kisi_listesi.txt", "r");

            char c;
            if (fp == NULL)
            {
                printf("\n» Rehber Acilamadi Tekrar Deneyiniz!");
            }
            else
            { // Kişi listesi görüntüleniyor
                printf("\n» Rehber Acildi Kisi Listesi Goruntuleniyor!\n\n");
                printf("╔══════════════════════╦════╣ Kisi Listesi ╠════╦══════════════════════╗\n");
                printf("║ %-20s ║ %-22s ║ %-20s ║\n", "Ad", "Soyad", "Numara");
                c = fgetc(fp);
                printf("╠══════════════════════╬════════════════════════╬══════════════════════╣\n");
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fp);
                }
                printf("╚══════════════════════╩════════════════════════╩══════════════════════╝\n\n");
            }

            fclose(fp);
        }
        break;
        case 4:
        { // Kişi düzenleme işlemi
            printf("\n» Rehber Acildi Kisi Duzenleme Islemine Baslayabilirsiniz.\n\n");

            FILE *fp = fopen("kisi_listesi.txt", "r");
            char c;
            if (fp == NULL)
            {
                printf("\n» Rehber Acilamadi Tekrar Deneyiniz!");
            }
            else
            { // Kişi listesi görüntüleniyor
                printf("\n» Rehber Acildi Kisi Listesi Goruntuleniyor!\n\n");
                printf("╔══════════════════════╦════╣ Kisi Listesi ╠════╦══════════════════════╗\n");
                printf("║ %-20s ║ %-22s ║ %-20s ║\n", "Ad", "Soyad", "Numara");
                c = fgetc(fp);
                printf("╠══════════════════════╬════════════════════════╬══════════════════════╣\n");
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fp);
                }
                printf("╚══════════════════════╩════════════════════════╩══════════════════════╝\n\n");
            }

            fclose(fp);
            int kisiBulundu = 0;

            do
            {
                char duzenlenecekIsim[25];
                // Düzenlenecek kişinin ismini alıyoruz
                printf("╔═══════════════════════════╣ Kisi Duzenleme ╠════════════════════════════\n");
                printf("║ » Duzenlemek istediginiz kisinin ismini giriniz: ");
                scanf("%24s", duzenlenecekIsim);
                printf("╚═════════════════════════════════════════════════════════════════════════\n");

                FILE *fp = fopen("kisi_listesi.txt", "r");
                FILE *fs = fopen("gecici_dosya.txt", "w");

                char line[2000];
                int foundCount = 0;
                char foundLines[100][2000]; // Max 100 eşleşen kayıt
                // Dosyayı tarayıp eşleşen kayıtları buluyoruz
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, duzenlenecekIsim) != NULL)
                    {
                        strcpy(foundLines[foundCount++], line);
                    }
                }
                fclose(fp);

                if (foundCount == 0)
                {
                    printf("\n» Kisi bulunamadi. Lutfen gecerli bir isim giriniz.\n\n");
                }
                else
                { // Bulunan kişileri listeliyoruz
                    printf("╔═══╦══════════════════════╦══╣ Bulunan Kisiler ╠═══╦══════════════════════╗\n");
                    for (int i = 0; i < foundCount; i++)
                    {
                        printf("║ %d %s", i + 1, foundLines[i]);
                    }
                    printf("╚══════════════════════════╩════════════════════════╩══════════════════════╝\n");
                    int secim;
                    printf("» Duzenlemek istediginiz kisiyi seciniz (1-%d): ", foundCount);
                    scanf("%d", &secim);

                    if (secim < 1 || secim > foundCount)
                    {
                        printf("\n» Gecersiz secim.\n");
                    }
                    else
                    { // Seçilen kişiyi düzenleme
                        FILE *fp = fopen("kisi_listesi.txt", "r");
                        FILE *fs = fopen("gecici_dosya.txt", "w");
                        int currentLine = 0;
                        int selectedLine = 0;

                        while (fgets(line, sizeof(line), fp) != NULL)
                        {
                            currentLine++;
                            if (currentLine == secim)
                            {
                                selectedLine = currentLine;
                                char ad[25], soyad[25], numara[25];
                                printf("║ » Yeni Ad: ");
                                scanf("%24s", ad);
                                printf("║ » Yeni Soyad: ");
                                scanf("%24s", soyad);
                                printf("║ » Yeni Numara: ");
                                scanf("%24s", numara);
                                printf("╚═════════════════════════════════════════════════════════════════════════\n");
                                // Yeni veriyi dosyaya yazıyoruz
                                fprintf(fs, "║ » %-18s ║ » %-20s ║ » %-18s ║\n", ad, soyad, numara);
                            }
                            else
                            {
                                fprintf(fs, "%s", line);
                            }
                        }

                        fclose(fp);
                        fclose(fs);

                        if (selectedLine == 0)
                        {
                            printf("\n» Kisi duzenleme islemi basarisiz.\n");
                            remove("gecici_dosya.txt");
                        }
                        else
                        {
                            printf("\n» Kisi duzenleme islemi basarili...\n\n");
                            remove("kisi_listesi.txt");
                            rename("gecici_dosya.txt", "kisi_listesi.txt");
                        }
                    }
                }
            } while (kisiBulundu == 0);
        }
        break;

        case 5:
        { // Çıkış işlemi
            printf("\n════════════════════════════╣ Cikis yapiliyor... ╠════════════════════════════\n\n");
        }
        break;
        default:
            break;
        }
    } while (menu != 5); // Menüden çıkış yapana kadar döngüyü devam ettir

    return 0;
}
