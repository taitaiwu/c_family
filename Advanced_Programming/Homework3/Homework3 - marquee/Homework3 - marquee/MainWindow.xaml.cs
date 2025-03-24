using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace Homework3___marquee
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private DispatcherTimer dispatcherTimer;
        private bool dire1 = false;
        private bool dire2 = false;
        private string move = "";
        private string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);

        public MainWindow()
        {
            InitializeComponent();

            WindowStartupLocation = WindowStartupLocation.CenterScreen;

            dispatcherTimer = new DispatcherTimer();
            dispatcherTimer.Tick += new EventHandler(dispatcherTimer_Tick);
            dispatcherTimer.Interval = TimeSpan.FromMilliseconds(100);

            Uri uri1 = new Uri(appStartPath + @"/picture/Tom.png");
            Uri uri2 = new Uri(appStartPath + @"/picture/Jerry.png");

            BitmapImage image1 = new BitmapImage(uri1);
            BitmapImage image2 = new BitmapImage(uri2);

            tom.Source = image1;
            jerry.Source = image2;
        }

        private void enter_Click(object sender, RoutedEventArgs e)
        {
            marquee.Content = marqueeword.Text;

            Uri uri1 = new Uri(appStartPath + @"/picture/Tom.png");
            Uri uri2 = new Uri(appStartPath + @"/picture/Jerry.png");

            BitmapImage image1 = new BitmapImage(uri1);
            BitmapImage image2 = new BitmapImage(uri2);

            if (marqueeword.Text == "Tom and Jerry" && time.IsChecked == false)
            {
                tom.Source = image1;
                jerry.Source = image2;
            }

            else if (marqueeword.Text == "Tom" && time.IsChecked == false)
            {
                tom.Source = image1;
                jerry.Source = null;
            }

            else if (marqueeword.Text == "Jerry" && time.IsChecked == false)
            {
                tom.Source = null;
                jerry.Source = image2;
            }

            else
            {
                tom.Source = null ;
                jerry.Source = null;
            }
        }

        private void move_click(object sender, RoutedEventArgs e)
        {
            RadioButton radioButton = sender as RadioButton;
            move = radioButton.Name.ToString();
            dispatcherTimer.Start();
        }

        private void option_click(object sender, RoutedEventArgs e)
        {
            CheckBox checkBox = sender as CheckBox;
            dispatcherTimer.Start();
        }

        private void dispatcherTimer_Tick(object sender, EventArgs e)
        {
            Random random = new Random();

            if (move == "lr")
            {
                if (time.IsChecked == false)
                {
                    if (marquee.FontSize > 0 && marquee.FontSize <= 10)
                    {
                        if (marquee.Margin.Left <= -1270) dire1 = true;
                        else if (marquee.Margin.Left >= 1140) dire1 = false;
                    }

                    else if (marquee.FontSize > 10 && marquee.FontSize <= 20)
                    {
                        if (marquee.Margin.Left <= -1200) dire1 = true;
                        else if (marquee.Margin.Left >= 1100) dire1 = false;
                    }

                    else if (marquee.FontSize > 20 && marquee.FontSize <= 30)
                    {
                        if (marquee.Margin.Left <= -1100) dire1 = true;
                        else if (marquee.Margin.Left >= 1050) dire1 = false;
                    }

                    else if (marquee.FontSize > 30 && marquee.FontSize <= 40)
                    {
                        if (marquee.Margin.Left <= -1050) dire1 = true;
                        else if (marquee.Margin.Left >= 1030) dire1 = false;
                    }

                    else if (marquee.FontSize > 40 && marquee.FontSize <= 50)
                    {
                        if (marquee.Margin.Left <= -1000) dire1 = true;
                        else if (marquee.Margin.Left >= 990) dire1 = false;
                    }
                }

                else
                {
                    if (marquee.FontSize > 0 &&  marquee.FontSize <=25)
                    {
                        if (marquee.Margin.Left <= -1000) dire1 = true;
                        else if (marquee.Margin.Left >= 840) dire1 = false;
                    }

                    else if (marquee.FontSize > 25 &&  marquee.FontSize <= 50)
                    {
                        if (marquee.Margin.Left <= -650) dire1 = true;
                        else if (marquee.Margin.Left >= 650) dire1 = false;
                    }
                }

                if (dire1 == true) marquee.Margin = new Thickness(marquee.Margin.Left + 10, marquee.Margin.Top, marquee.Margin.Right, marquee.Margin.Bottom);
                else marquee.Margin = new Thickness(marquee.Margin.Left - 10, marquee.Margin.Top, marquee.Margin.Right, marquee.Margin.Bottom);
            }

            else if (move == "ud")
            {
                if (marquee.FontSize > 0 &&  marquee.FontSize <= 25)
                {
                    if (marquee.Margin.Top <= -670) dire1 = true;
                    else if (marquee.Margin.Top >= 260) dire1 = false;
                }

                else if(marquee.FontSize >25 && marquee.FontSize <=50)
                {
                    if (marquee.Margin.Top <= -610) dire1 = true;
                    else if (marquee.Margin.Top >= 210) dire1 = false;
                }

                if (dire1 == true) marquee.Margin = new Thickness(marquee.Margin.Left, marquee.Margin.Top + 10, marquee.Margin.Right, marquee.Margin.Bottom);
                else marquee.Margin = new Thickness(marquee.Margin.Left, marquee.Margin.Top - 10, marquee.Margin.Right, marquee.Margin.Bottom);
            }

            else if (move == "jump")
            {
                if (time.IsChecked == false)
                {
                    if (marquee.FontSize > 0 && marquee.FontSize <= 10)
                    {
                        if (marquee.Margin.Left <= -1270) dire1 = true;
                        else if (marquee.Margin.Left >= 1140) dire1 = false;
                    }

                    else if (marquee.FontSize > 10 && marquee.FontSize <= 20)
                    {
                        if (marquee.Margin.Left <= -1200) dire1 = true;
                        else if (marquee.Margin.Left >= 1100) dire1 = false;
                    }

                    else if (marquee.FontSize > 20 && marquee.FontSize <= 30)
                    {
                        if (marquee.Margin.Left <= -1100) dire1 = true;
                        else if (marquee.Margin.Left >= 1050) dire1 = false;
                    }

                    else if (marquee.FontSize > 30 && marquee.FontSize <= 40)
                    {
                        if (marquee.Margin.Left <= -1050) dire1 = true;
                        else if (marquee.Margin.Left >= 1030) dire1 = false;
                    }

                    else if (marquee.FontSize > 40 && marquee.FontSize <= 50)
                    {
                        if (marquee.Margin.Left <= -1000) dire1 = true;
                        else if (marquee.Margin.Left >= 990) dire1 = false;
                    }
                }

                else
                {
                    if (marquee.FontSize > 0 && marquee.FontSize <= 25)
                    {
                        if (marquee.Margin.Left <= -1000) dire1 = true;
                        else if (marquee.Margin.Left >= 840) dire1 = false;
                    }

                    else if (marquee.FontSize > 25 && marquee.FontSize <= 50)
                    {
                        if (marquee.Margin.Left <= -650) dire1 = true;
                        else if (marquee.Margin.Left >= 650) dire1 = false;
                    }
                }

                if (marquee.FontSize > 0 && marquee.FontSize <= 25)
                {
                    if (marquee.Margin.Top <= -670) dire2 = true;
                    else if (marquee.Margin.Top >= 260) dire2 = false;
                }

                else if (marquee.FontSize > 25 && marquee.FontSize <= 50)
                {
                    if (marquee.Margin.Top <= -610) dire2 = true;
                    else if (marquee.Margin.Top >= 210) dire2 = false;
                }

                if (dire1 == true && dire2 == true)  marquee.Margin = new Thickness(marquee.Margin.Left + 10, marquee.Margin.Top + 10, marquee.Margin.Right, marquee.Margin.Bottom);
                else if (dire1 == true && dire2 == false) marquee.Margin = new Thickness(marquee.Margin.Left + 10, marquee.Margin.Top - 10, marquee.Margin.Right, marquee.Margin.Bottom);
                else if (dire1 == false && dire2 == true) marquee.Margin = new Thickness(marquee.Margin.Left - 10, marquee.Margin.Top + 10, marquee.Margin.Right, marquee.Margin.Bottom);
                else if (dire1 == false && dire2 == false) marquee.Margin = new Thickness(marquee.Margin.Left - 10, marquee.Margin.Top - 10, marquee.Margin.Right, marquee.Margin.Bottom);
            }

            else if (move == "random") marquee.Margin = new Thickness(random.Next(-950, 950), random.Next(-610, 210), 0, 0);


            if (fncolor.IsChecked == true)
            {
                Color color = Color.FromRgb((byte)random.Next(256), (byte)random.Next(256), (byte)random.Next(256));
                marquee.Foreground = new SolidColorBrush(color);
            }

            if (bgcolor.IsChecked == true)
            {
                Color color = Color.FromRgb((byte)random.Next(200,256), (byte)random.Next(200,256), (byte)random.Next(200,256));
                background.Background = new SolidColorBrush(color);
            }

            if (rdsize.IsChecked == true) marquee.FontSize = random.Next(1, 50);

            if (time.IsChecked == true)
            {
                marquee.Content = DateTime.Now.ToString("F");
                marquee.Width = 710;

                tom.Source = null;
                jerry.Source = null;
            }

            else
            {
                marquee.Content = marqueeword.Text;
                marquee.Width = 400;
            }
        }

        private void speed_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (dispatcherTimer != null)
            {
                if (lr.IsChecked == true || ud.IsChecked == true || jump.IsChecked == true ) dispatcherTimer.Interval = TimeSpan.FromMilliseconds(speed.Value);
                else if (random.IsChecked == true || fncolor.IsChecked == true || bgcolor.IsChecked == true || rdsize.IsChecked == true) dispatcherTimer.Interval = TimeSpan.FromSeconds(speed.Value / 100);
            }
            speed_title.Content = "※Speed : " + (51 - Math.Ceiling(speed.Value));
        }

        private void size_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            marquee.FontSize = (int)size.Value;
            size_title.Content = "※Font Size : " + (int)size.Value;
        }

        private void function_click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;

            if (button == pause) dispatcherTimer.Stop();
            else if (button == resume) dispatcherTimer.Start();
            else if (button == reset)
            {
                dispatcherTimer.Stop();
                move = "";

                background.Background = Brushes.White;
                marquee.Foreground = Brushes.Black;
                marquee.Margin = new Thickness(0, -200, 0, 0);
                marquee.Content = "Tom and Jerry";

                lr.IsChecked = false;
                ud.IsChecked = false;
                jump.IsChecked = false;
                random.IsChecked = false;
                fncolor.IsChecked = false;
                bgcolor.IsChecked = false ;
                rdsize.IsChecked = false ;
                time.IsChecked = false ;

                marqueeword.Text = "Tom and Jerry";

                speed.Value = 26;
                size.Value = 25;

            }
        }
    }
}