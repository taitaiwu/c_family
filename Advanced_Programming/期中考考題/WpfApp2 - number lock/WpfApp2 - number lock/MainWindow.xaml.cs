using Microsoft.VisualBasic;
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

namespace WpfApp2___number_lock
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            WindowStartupLocation = WindowStartupLocation.CenterScreen;
        }

        private void num_click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;

            outcome.Content = "";
            outcome.Background = Brushes.Transparent;

            if (textbox1.Text == "*") textbox1.Text = button.Content.ToString();
            else if (textbox2.Text == "*") textbox2.Text = button.Content.ToString();
            else if (textbox3.Text == "*") textbox3.Text = button.Content.ToString();
            else if (textbox4.Text == "*")
            {
                textbox4.Text = button.Content.ToString();

                //密碼預設0520
                if (textbox1.Text == "0" && textbox2.Text == "5" && textbox3.Text == "2" && textbox4.Text == "0")
                {
                    outcome.Content = "success";
                    outcome.Background = Brushes.White;

                    textbox1.Text = "*";
                    textbox2.Text = "*";
                    textbox3.Text = "*";
                    textbox4.Text = "*";
                }

                else 
                {
                    outcome.Content = "error";
                    outcome.Background = Brushes.White;

                    textbox1.Text = "*";
                    textbox2.Text = "*";
                    textbox3.Text = "*";
                    textbox4.Text = "*";
                }
            }
        }

        private void back_click(object sender, RoutedEventArgs e)
        {
            outcome.Content = "";
            outcome.Background = Brushes.Transparent;

            if (textbox4.Text != "*") textbox4.Text = "*";
            else if (textbox3.Text != "*") textbox3.Text = "*";
            else if (textbox2.Text != "*") textbox2.Text = "*";
            else if (textbox1.Text != "*") textbox1.Text = "*";
        }

        private void clear_click(object sender, RoutedEventArgs e)
        {
            outcome.Content = "";
            outcome.Background = Brushes.Transparent;

            textbox1.Text = "*";
            textbox2.Text = "*";
            textbox3.Text = "*";
            textbox4.Text = "*";
        }
    }
}