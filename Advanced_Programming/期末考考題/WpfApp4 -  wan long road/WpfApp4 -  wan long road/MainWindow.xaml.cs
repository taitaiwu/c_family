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

namespace WpfApp4____wan_long_road
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

        private void move_click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;

            if (button.Content != null)
            {
               
            }
        }

        private void start_Click(object sender, RoutedEventArgs e)
        {
            Random random = new Random();

            List<int> list = new List<int>();

            for (int i = 0; i < 10; i++)
            {
                list.Add(random.Next(1,10));
                int index = list.Count;

                for (int j = 0; j < list.Count-1; j++)
                {
                    while (list[j] == list[index])
                    {
                        list.RemoveAt(list[index]);
                        list.Add(random.Next(1, 10));
                    }
                }
            }

            button1.Content = list[0];
            button2.Content = list[1];
            button3.Content = list[2];
            button4.Content = list[3];
            button5.Content = list[4];
            button6.Content = list[5];
            button7.Content = list[6];
            button8.Content = list[7];
            button9.Content = list[8];
        }
    }
}