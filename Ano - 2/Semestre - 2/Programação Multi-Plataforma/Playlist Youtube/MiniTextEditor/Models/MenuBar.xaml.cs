using System.Windows.Controls;

namespace MiniTextEditor.Models
{
    /// <summary>
    /// Interação lógica para MenuBar.xam
    /// </summary>
    public partial class MenuBar : UserControl
    {
        public event EventHandler OpenClicked;
        public event EventHandler CloseClicked;
        public event EventHandler SaveClicked;
        public event EventHandler ExitClicked;
        public MenuBar()
        {
            InitializeComponent();
        }

        private void OpenFile(object sender, System.Windows.RoutedEventArgs e)
        {
            OpenClicked?.Invoke(this, EventArgs.Empty);
        }

        private void CloseFile(object sender, System.Windows.RoutedEventArgs e)
        {
            CloseClicked?.Invoke(this, EventArgs.Empty);
        }

        private void SaveFile(object sender, System.Windows.RoutedEventArgs e)
        {
            SaveClicked?.Invoke(this, EventArgs.Empty);
        }

        private void Exit(object sender, System.Windows.RoutedEventArgs e)
        {
            ExitClicked?.Invoke(this, EventArgs.Empty);
        }
    }
}
