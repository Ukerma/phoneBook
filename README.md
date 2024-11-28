<h1>📒 Simple Phone Directory System</h1>
<p>
   This project implements a basic phone directory application in C. It allows users to add, view, delete, and update contact details in a text-based menu interface. The data is stored persistently in a file named <code>kisi_listesi.txt</code>.
</p>

<h2>🛠️ Features</h2>
<ul>
   <li> Add new contacts (name, surname, and phone number).</li>
   <li> Delete existing contacts by name with an option to select among duplicates.</li>
   <li> Update existing contact information.</li>
   <li> View all saved contacts in a formatted table.</li>
   <li> Persistent data storage in a text file.</li>
</ul>

<h2>⚙️ Technologies Used</h2>
<ul>
   <li> <strong>Language:</strong> C</li>
   <li> <strong>Libraries:</strong> 
      <ul>
         <li><code>stdio.h</code>: For standard input/output operations.</li>
         <li><code>stdlib.h</code>: For file operations and memory management.</li>
         <li><code>string.h</code>: For string manipulation functions.</li>
      </ul>
   </li>
</ul>

<h2>🚀 How to Use</h2>
<ol>
   <li> Clone or download the repository to your local machine.</li>
   <li> Compile the program using any C compiler (e.g., GCC):
      <pre><code>gcc -o phone_directory phone_directory.c</code></pre>
   </li>
   <li> Run the compiled executable:
      <pre><code>./phone_directory</code></pre>
   </li>
   <li> Interact with the menu to manage your phone directory.</li>
</ol>

<h2>💡 Example Output</h2>
<pre>
╔═════════════════════╗
║                     ║
║  -MENU-             ║
║   1-Numara Ekle     ║
║   2-Numara Sil      ║
║   3-Kisi Listesi    ║
║   4-Kisi Duzenle    ║
║   5-Cikis           ║
║                     ║
╚═════════════════════╝

» Lutfen yapmak istediginiz islemi seciniz: 1

╔═══════════════════════════╣ Numara Ekleme ╠════════════════════════════
║ » Ad: Ahmet
║ » Soyad: Yılmaz
║ » Numara: 1234567890
╚════════════════════════════════════════════════════════════════════════

» Kisi ekleme islemi basarili...
</pre>

<h2>👨‍💻 Author</h2>
<p>
   This project was developed by <strong>Umut Kerim ACAR (ukerma)</strong>.</p>
