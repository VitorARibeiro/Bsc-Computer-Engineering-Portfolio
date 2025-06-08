using MVVM_Listagem.Model;
using MVVM_Listagem.MVVM;
using System.Collections.ObjectModel;

namespace MVVM_Listagem.ViewModel
{
    internal class MainWindowViewModel : ViewModelBase
    {

        public ObservableCollection<Item> Items { get; set; } //item referencia a classe Item que fica na pasta Models
        public RelayCommand AddComand => new RelayCommand(execute => AddItem());
        public RelayCommand RemoveComand => new RelayCommand(execute => RemoveItem(), canExecute => _SelectedItem != null);
        
        public MainWindowViewModel() {

            Items = new ObservableCollection<Item>();


        } //Construtor da Classe

        private Item _SelectedItem; //Item selecionado para obter dados e mostrar na parte de lado

        public Item SelectedItem
        {
            get { return _SelectedItem; }
            set { 
                
                _SelectedItem = value;
                OnPropertyChanged(); // Notificar que a propriedade foi alterado, Codigo presente na pasta MVVM
            }
        }

        private void AddItem()
        {
            Items.Add(new Item { 
                
                Name = "new Item", 
                SerialNumber = "XXXXXX", 
                Quantity = 0 
            } );
        }

        private void RemoveItem()
        {

            Items.Remove( _SelectedItem );
        }

    }
}
