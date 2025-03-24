using System.Diagnostics;
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
using static System.Net.Mime.MediaTypeNames;

namespace WpfApp3___polynomial
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

            string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);
            Uri uri = new Uri(appStartPath + @"/math picture.png");
            BitmapImage image = new BitmapImage(uri);
            image1.Source = image;
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            bool result1 = int.TryParse(textbox1.Text, out int value1);
            bool result2 = int.TryParse(textbox2.Text, out int value2);
            bool result3 = int.TryParse(textbox3.Text, out int value3);

            if (result1 ==true && result2 == true && result3 == true)
            {
                double x = int.Parse(textbox1.Text);
                double a = int.Parse(textbox2.Text);
                double b = int.Parse(textbox3.Text);

                double temp1 = a * Math.Pow(x, 4) + b * Math.Pow(x, 0.5);

                if (temp1 < 0) temp1 *= -1;

                double answer = temp1 + Math.Pow(x, 4);
                answer1.Text = "Answer : " + Math.Round(answer, 8).ToString();
                answer1.Background = Brushes.LightBlue;
                answer1.Foreground = Brushes.Black;
                answer1.TextAlignment = TextAlignment.Left;
            }

            else
            {
                answer1.Text = "Input Error!";
                answer1.Background = Brushes.Red;
                answer1.Foreground = Brushes.White;
                answer1.TextAlignment = TextAlignment.Center;
            }
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            bool result1 = int.TryParse(textbox4.Text,out int value1);
            bool result2 = int.TryParse(textbox5.Text, out int value2);
            bool result3 = int.TryParse(textbox6.Text, out int value3);
            bool result4 = int.TryParse(textbox7.Text, out int value4);

            if (result1 == true && result2 == true && result3 == true && result4 == true)
            {
                double x = int.Parse(textbox4.Text);
                double a = int.Parse(textbox5.Text);
                double b = int.Parse(textbox6.Text);
                double c = int.Parse(textbox7.Text);

                double answer = (a * Math.Pow(x, 3) - b * Math.Pow(x, 02) + c * x)/7;

                answer2.Text = "Answer : " + Math.Round(answer, 8).ToString();
                answer2.Background = Brushes.LightBlue;
                answer2.Foreground = Brushes.Black;
                answer2.TextAlignment = TextAlignment.Left;
            }

            else
            {
                answer2.Text = "Input Error!";
                answer2.Background = Brushes.Red;
                answer2.Foreground = Brushes.White;
                answer2.TextAlignment = TextAlignment.Center;
            }
        }
    }
}