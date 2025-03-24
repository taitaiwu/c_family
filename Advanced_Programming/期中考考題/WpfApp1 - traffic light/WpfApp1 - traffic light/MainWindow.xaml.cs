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

namespace WpfApp1___traffic_light
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

        int counter = 0;

        private void direction(object sender, RoutedEventArgs e)
        {
            Button button =sender as Button;
            
            if (button == left) counter--;
            else if (button == right) counter++;

            if (counter < 0) counter += 3;

            if (counter >= 0)
            {
                if (counter % 3 == 0)
                {
                    label1.Background = Brushes.Red;
                    label2.Background = Brushes.Yellow;
                    label3.Background = Brushes.Green;

                    label1.Content = "紅色";
                    label2.Content = "黃色";
                    label3.Content = "綠色";
                }

                else if (counter % 3 == 1)
                {
                    label1.Background = Brushes.Green;
                    label2.Background = Brushes.Red;
                    label3.Background = Brushes.Yellow;

                    label1.Content = "綠色";
                    label2.Content = "紅色";
                    label3.Content = "黃色";
                }

                else if (counter % 3 == 2)
                {
                    label1.Background = Brushes.Yellow;
                    label2.Background = Brushes.Green;
                    label3.Background = Brushes.Red;

                    label1.Content = "黃色";
                    label2.Content = "綠色";
                    label3.Content = "紅色";
                }
            }
        }
    }
}