using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp3___xiao_san_tong_ticket_booking
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Dictionary<string, List<string>> ticket;
        private double total = 0;

        public MainWindow()
        {
            InitializeComponent();
            InitializeDate();
            combox1.ItemsSource = ticket.Keys;
        }

        private void InitializeDate()
        {
            ticket = new Dictionary<string, List<string>>()
            {
                {"金門", new List<string>(){"五通","石井"}},
                {"五通", new List<string>(){"金門"}},
                {"石井", new List<string>(){"金門"}}
            };
        }

        private void combox1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (ticket.ContainsKey(combox1.SelectedItem.ToString())) combox2.ItemsSource = ticket[combox1.SelectedItem.ToString()];
        }

        private void ticket_check(object sender, RoutedEventArgs e)
        {
            if (combox1.SelectedItem == "金門" && combox2.SelectedItem == "五通") total = 650;
            else if (combox1.SelectedItem == "金門" && combox2.SelectedItem == "石井") total = 750;
            else if (combox1.SelectedItem == "五通" && combox2.SelectedItem == "金門") total = 625;
            else if (combox1.SelectedItem == "石井" && combox2.SelectedItem == "金門") total = 715;

            RadioButton radioButton = sender as RadioButton;

            if (all.IsChecked == true) total *= 1;
            else if (live.IsChecked == true) total *= 0.8;
            else if (yu.IsChecked == true) total *= 0.5;
            else if (baby.IsChecked == true) total *= 0.1;

            price.Content = "Price : " + (int)total; 
        }

        private void addon(object sender, RoutedEventArgs e)
        {
            if (combox1.SelectedItem != null && combox2.SelectedItem != null)
            {
                if (vip.IsChecked == true) total += 100;
                else if (meal.IsChecked == true) total += 150;
            }

            price.Content = "Price : " + (int)total;
        }

        private void addon_cancel(object sender, RoutedEventArgs e)
        {
            if (combox1.SelectedItem != null && combox2.SelectedItem != null)
            {
                if (vip.IsChecked == false) total -= 100;
                else if (meal.IsChecked == false) total -= 150;
            }

            price.Content = "Price : " + (int)total;
        }
    }
}