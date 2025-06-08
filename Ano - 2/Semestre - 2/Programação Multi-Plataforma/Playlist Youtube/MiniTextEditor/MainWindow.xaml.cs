using Microsoft.Win32;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace MiniTextEditor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string FilePath = "";
        public MainWindow()
        {
            InitializeComponent();
        }
        private void MenuOpenClick(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            ofd.Title = ("Pls Pick a file"); //aparece no titulo do picker
            ofd.Filter = "Text Files | *.txt;*.c"; //so aparece .txt
            bool? success = ofd.ShowDialog(); // para abrir o file picker


            if (success == true)
            {
                FilePath = ofd.FileName;
                TxtBox.Text = File.ReadAllText(FilePath);
            }
        }
        private void MenuSaveClick(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(TxtBox.Text))
            {
                MessageBox.Show("Ficheiro Vazio", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return ;
            }

            try
            {
                File.WriteAllText(FilePath, TxtBox.Text);
                MessageBox.Show("File saved successfully.");
            }
            catch (IOException ex)
            {
                MessageBox.Show($"An error occurred while saving the file: {ex.Message}");
            }

        }
        private void MenuCloseClick(object sender, EventArgs e)
        {
            TxtBox.Text = null;
            FilePath = "";

        }
        private void MenuExitClick(object sender, EventArgs e)
        {
            Close();
        }
    }
}