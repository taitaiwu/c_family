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

namespace Homework1___direction
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

        decimal counter = 0;

        private void direction_Click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;

            if (button == left) counter--;
            else if (button == right) counter++;

            if (counter >= 0 )
            {
                if (counter%4  == 1)
                {
                    label1.Content = "N";
                    label2.Content = "E";
                    label3.Content = "S";
                    label0.Content = "W";

                    label1.Foreground = Brushes.Black;
                    label2.Foreground = Brushes.Red;
                    label3.Foreground = Brushes.Green;
                    label0.Foreground = Brushes.Blue;
                }

                else if (counter % 4 == 2)
                {
                    label1.Content = "W";
                    label2.Content = "N";
                    label3.Content = "E";
                    label0.Content = "S";

                    label1.Foreground = Brushes.Blue;
                    label2.Foreground = Brushes.Black;
                    label3.Foreground = Brushes.Red;
                    label0.Foreground = Brushes.Green;
                }

                else if (counter % 4 == 3)
                {
                    label1.Content = "S";
                    label2.Content = "W";
                    label3.Content = "N";
                    label0.Content = "E";

                    label1.Foreground = Brushes.Green;
                    label2.Foreground = Brushes.Blue;
                    label3.Foreground = Brushes.Black;
                    label0.Foreground = Brushes.Red;
                }

                else if (counter % 4 == 0)
                {
                    label1.Content = "E";
                    label2.Content = "S";
                    label3.Content = "W";
                    label0.Content = "N";

                    label1.Foreground = Brushes.Red;
                    label2.Foreground = Brushes.Green;
                    label3.Foreground = Brushes.Blue;
                    label0.Foreground = Brushes.Black;
                }
            }

            else
            {
                if (counter % 4 == -1)
                {
                    label1.Content = "S";
                    label2.Content = "W";
                    label3.Content = "N";
                    label0.Content = "E";

                    label1.Foreground = Brushes.Green;
                    label2.Foreground = Brushes.Blue;
                    label3.Foreground = Brushes.Black;
                    label0.Foreground = Brushes.Red;


                }

                else if (counter % 4 == -2)
                {
                    label1.Content = "W";
                    label2.Content = "N";
                    label3.Content = "E";
                    label0.Content = "S";

                    label1.Foreground = Brushes.Blue;
                    label2.Foreground = Brushes.Black;
                    label3.Foreground = Brushes.Red;
                    label0.Foreground = Brushes.Green;
                }

                else if (counter % 4 == -3)
                {
                    label1.Content = "N";
                    label2.Content = "E";
                    label3.Content = "S";
                    label0.Content = "W";

                    label1.Foreground = Brushes.Black;
                    label2.Foreground = Brushes.Red;
                    label3.Foreground = Brushes.Green;
                    label0.Foreground = Brushes.Blue;
                }

                else if (counter % 4 == 0)
                {
                    label1.Content = "E";
                    label2.Content = "S";
                    label3.Content = "W";
                    label0.Content = "N";

                    label1.Foreground = Brushes.Red;
                    label2.Foreground = Brushes.Green;
                    label3.Foreground = Brushes.Blue;
                    label0.Foreground = Brushes.Black;
                }
            }
        }
    }
}