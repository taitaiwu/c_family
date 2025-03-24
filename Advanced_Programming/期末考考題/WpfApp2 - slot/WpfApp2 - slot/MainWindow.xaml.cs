using System;
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

namespace WpfApp2___slot
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private DispatcherTimer dispatcherTimer1;
        private DispatcherTimer dispatcherTimer2;
        private DispatcherTimer dispatcherTimer3;

        private bool stop1 = false;
        private bool stop2 = false;
        private bool stop3 = false;

        private int num1 = 0;
        private int num2 = 0;
        private int num3 = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            button1.IsEnabled = false;

            dispatcherTimer1 = new DispatcherTimer();
            dispatcherTimer2 = new DispatcherTimer();
            dispatcherTimer3 = new DispatcherTimer();

            dispatcherTimer1.Tick += new EventHandler(dispatcherTimer_Tick1);
            dispatcherTimer2.Tick += new EventHandler(dispatcherTimer_Tick2);
            dispatcherTimer3.Tick += new EventHandler(dispatcherTimer_Tick3);

            dispatcherTimer1.Interval = TimeSpan.FromMilliseconds(3);
            dispatcherTimer2.Interval = TimeSpan.FromMilliseconds(3);
            dispatcherTimer3.Interval = TimeSpan.FromMilliseconds(3);

            dispatcherTimer1.Start();
            dispatcherTimer2.Start();
            dispatcherTimer3.Start();
        }

        private void dispatcherTimer_Tick1(object? sender, EventArgs e)
        {
            Random random = new Random();

            num1 = random.Next(1, 12);

            string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);

            Uri uri1 = new Uri(appStartPath + @"/slot/" + num1 + ".png", UriKind.Absolute);
            BitmapImage bitmapImage1 = new BitmapImage(uri1);
            image1.Source = bitmapImage1; 
        }

        private void dispatcherTimer_Tick2(object? sender, EventArgs e)
        {
            Random random = new Random();

            num2 = random.Next(1, 12);

            string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);
            Uri uri2 = new Uri(appStartPath + @"/slot/" + num2 + ".png", UriKind.Absolute);
            BitmapImage bitmapImage2 = new BitmapImage(uri2);
            image2.Source = bitmapImage2;
        }

        private void dispatcherTimer_Tick3(object? sender, EventArgs e)
        {
            Random random = new Random();

            num3 = random.Next(1, 12);

            string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);
            Uri uri3 = new Uri(appStartPath + @"/slot/" + num3 + ".png", UriKind.Absolute);
            BitmapImage bitmapImage3 = new BitmapImage(uri3);
            image3.Source = bitmapImage3;
        }
        private void image1_MouseDown(object sender, MouseButtonEventArgs e)
        {
            dispatcherTimer1.Stop();
            stop1 = true;
            score();
        }

        private void image2_MouseDown(object sender, MouseButtonEventArgs e)
        {
            dispatcherTimer2.Stop();
            stop2 = true;
            score();
        }

        private void image3_MouseDown(object sender, MouseButtonEventArgs e)
        {
            dispatcherTimer3.Stop();
            stop3 = true;
            score();
        }

        private void score()
        {
            if  (stop1 == true && stop2 == true && stop3 == true)
            {
                if ((num1 == num2) && (num2 == num3) && (num1 == num3)) score_result.Content = "Score : 100";
                else if ((num1 != num2) && (num1 != num3) && (num2 != num3)) score_result.Content = "Score : 0";
                else score_result.Content = "Score : 50";

                stop1 = stop2 = stop3 = false;

                button1.IsEnabled = true;
            }
        }
    }
}