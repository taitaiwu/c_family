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
using System.Windows.Threading;

namespace WpfApp5___dice
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);
        DispatcherTimer dispatcherTimer;

        public MainWindow()
        {
            InitializeComponent();
            WindowStartupLocation = WindowStartupLocation.CenterScreen;

            dispatcherTimer = new DispatcherTimer();
            dispatcherTimer.Tick += new EventHandler(dispatcherTimer_Tick);
            dispatcherTimer.Interval = TimeSpan.FromSeconds(0.5);
            dispatcherTimer.Start();
        }

        private void dispatcherTimer_Tick(object? sender, EventArgs e)
        {
            Random random = new Random();

            Uri uri1 = new Uri(appStartPath + @"/default/" + random.Next(1,9) + ".png" , UriKind.Absolute);
            Uri uri2 = new Uri(appStartPath + @"/default/" + random.Next(1, 9) + ".png", UriKind.Absolute);
            Uri uri3 = new Uri(appStartPath + @"/default/" + random.Next(1, 9) + ".png", UriKind.Absolute);

            BitmapImage bitmapImage1 = new BitmapImage(uri1);
            BitmapImage bitmapImage2 = new BitmapImage(uri2);
            BitmapImage bitmapImage3 = new BitmapImage(uri3);

            image1.Source = bitmapImage1;
            image2.Source = bitmapImage2;
            image3.Source = bitmapImage3;
        }

        private void dice_Click(object sender, RoutedEventArgs e)
        {
            Random random = new Random();
            dispatcherTimer.Stop();

            int a = random.Next(1, 7);
            int b = random.Next(1, 7);
            int c = random.Next(1, 7);

            label1.Content = a.ToString();
            label2.Content = b.ToString();
            label3.Content = c.ToString();

            Uri uri1 = new Uri(appStartPath + @"/picture/" + a + ".png", UriKind.Absolute);
            Uri uri2 = new Uri(appStartPath + @"/picture/" + b + ".png", UriKind.Absolute);
            Uri uri3 = new Uri(appStartPath + @"/picture/" + c + ".png", UriKind.Absolute);

            BitmapImage bitmapImage1 = new BitmapImage(uri1);
            BitmapImage bitmapImage2 = new BitmapImage(uri2);
            BitmapImage bitmapImage3 = new BitmapImage(uri3);

            image1.Source = bitmapImage1;
            image2.Source = bitmapImage2;
            image3.Source = bitmapImage3;

            int outcome1 = a + b + c;
            game1.Text = "A局分數 : " + outcome1;

            if (a == b && b == c && a == c) game2.Text = "B局分數 : 一色(豹子)";

            else if (a != b && b != c && a != c)
            {
                if (a == 1 && b == 2 && c == 3) game2.Text = "B局分數 : 逼基";
                else game2.Text = "B局分數 : 0";
            }

            else
            {
                if (a == b) game2.Text = "B局分數 : " + c;
                else if (a == c) game2.Text = "B局分數 : " + b;
                else if (b == c) game2.Text = "B局分數 : " + a;
            }
        }
    }
}