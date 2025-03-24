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

namespace Homework2___calculator_easy_
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void calculate(object sender, RoutedEventArgs e)
        {
            string str1 = textbox1.Text;
            string str2 = textbox2.Text;
            decimal result = 0;

            try
            {
                Button? button = sender as Button;

                if (button == plus) result = decimal.Parse(str1) + decimal.Parse(str2);
                else if (button == sub) result = decimal.Parse(str1) - decimal.Parse(str2);
                else if (button == mult) result = decimal.Parse(str1) * decimal.Parse(str2);
                else if (button == dive) result = decimal.Parse(str1) / decimal.Parse(str2);
                else if (button == mod) result = decimal.Parse(str1) % decimal.Parse(str2);
            }

            catch
            {
                MessageBox.Show("An error input A or B.");
            }

            textbox3.Text = result.ToString();
        }
    }
}