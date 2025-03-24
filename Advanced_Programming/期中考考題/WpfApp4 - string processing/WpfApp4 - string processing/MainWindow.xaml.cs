using System.Runtime.Intrinsics.X86;
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

namespace WpfApp4___string_processing
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

        private void process_Click(object sender, RoutedEventArgs e)
        {
            bool upper = false;
            bool lower = false;
            bool num = false;
            bool output = true;
            bool check1 = false;
            bool check2 = false;
            bool check3 = false;

            //check a
            if (a.Text.Length < 10)
            {
                a.Text = "Less than 10 CHARs";
                a.Background = Brushes.Red;
                a.Foreground = Brushes.White;
                a.HorizontalContentAlignment = HorizontalAlignment.Center;
                a.IsReadOnly = true;
                button1.IsEnabled = button2.IsEnabled = button3.IsEnabled = false;
            }

            else
            {
                for (int i = 0; i < a.Text.Length; i++)
                {
                    for (int j = 0; j < a.Text.Length; j++)
                    {
                        for (int k = 0; k < a.Text.Length; k++)
                        {
                            string v = a.Text[k].ToString();
                            num = int.TryParse(v, out int value);

                            if (num == true) break;
                        }

                        if (char.IsLower(a.Text[j]))
                        {
                            lower = true;
                            break;
                        }
                    }

                    if (char.IsUpper(a.Text[i]))
                    {
                        upper = true;
                        break;
                    }
                }

                if (!upper || !lower || !num)
                {
                    a.Text = "Input Error";
                    a.Background = Brushes.Yellow;
                    a.Foreground = Brushes.White;
                    a.HorizontalContentAlignment = HorizontalAlignment.Center;
                    a.IsReadOnly = true;
                    button1.IsEnabled = button2.IsEnabled = button3.IsEnabled = false;
                }

                else check1 = true;
            }

            //check b 
            upper = lower = num = false;
            if (b.Text.Length < 5)
            {
                b.Text = "Less than 5 CHARs";
                b.Background = Brushes.Red;
                b.Foreground = Brushes.White;
                b.HorizontalContentAlignment = HorizontalAlignment.Center;
                b.IsReadOnly = true;
                button1.IsEnabled = button2.IsEnabled = button3.IsEnabled = false;
            }

            else
            {
                for (int i = 0; i < b.Text.Length; i++)
                {
                    for (int j = 0; j < b.Text.Length; j++)
                    {
                        for (int k = 0; k < b.Text.Length; k++)
                        {
                            string v = b.Text[k].ToString();
                            num = int.TryParse(v, out int value);

                            if (num == true) break;
                        }

                        if (char.IsLower(b.Text[j]))
                        {
                            lower = true;
                            break;
                        }
                    }

                    if (char.IsUpper(b.Text[i]))
                    {
                        upper = true;
                        break;
                    }
                }

                if (!upper || !lower || !num)
                {
                    b.Text = "Input Error";
                    b.Background = Brushes.Yellow;
                    b.Foreground = Brushes.White;
                    b.HorizontalContentAlignment = HorizontalAlignment.Center;
                    b.IsReadOnly = true;
                    button1.IsEnabled = button2.IsEnabled = button3.IsEnabled = false;
                }

                else check2 = true;
            }

            //check c
            upper = lower = num = false;
            if (c.Text.Length < 5)
            {
                c.Text = "Less than 5 CHARs";
                c.Background = Brushes.Red;
                c.Foreground = Brushes.White;
                c.HorizontalContentAlignment = HorizontalAlignment.Center;
                c.IsReadOnly = true;
                button2.IsEnabled = button3.IsEnabled = false;
            }

            else
            {
                for (int i = 0; i < c.Text.Length; i++)
                {
                    for (int j = 0; j < c.Text.Length; j++)
                    {
                        for (int k = 0; k < c.Text.Length; k++)
                        {
                            string v = c.Text[k].ToString();
                            num = int.TryParse(v, out int value);

                            if (num == true) break;
                        }

                        if (char.IsLower(c.Text[j]))
                        {
                            lower = true;
                            break;
                        }
                    }

                    if (char.IsUpper(c.Text[i]))
                    {
                        upper = true;
                        break;
                    }
                }

                if (!upper || !lower || !num)
                {
                    c.Text = "Input Error";
                    c.Background = Brushes.Yellow;
                    c.Foreground = Brushes.White;
                    c.HorizontalContentAlignment = HorizontalAlignment.Center;
                    c.IsReadOnly = true;
                    button2.IsEnabled = button3.IsEnabled = false;
                }

                else check3 = true;
            }
           
            Button button = sender as Button;

            if (button == button1 && check1 && check2)
            {
                output1.Content = "※ Output : ";

                for (int i = 0; i < a.Text.Length; i++)
                {
                    for (int j = 0; j< b.Text.Length; j++)
                    {
                        if (a.Text[i] == b.Text[j])
                        {
                            output = false;
                            break;
                        }
                    }

                    if (output) output1.Content += a.Text[i].ToString();

                    output = true;
                }
            }

            else if ((button == button2 || button == button3) && check1 && check2 && check3)
            {
                int i = a.Text.IndexOf(b.Text);

                if (i != -1)
                {
                    if (button == button2)
                    {
                        i += b.Text.Length;
                        output1.Content = "※ Output : " + a.Text.Insert(i, c.Text);
                    }

                    else if (button == button3) output1.Content = "※ Output : " + a.Text.Replace(b.Text, c.Text);
                }

                else output1.Content = "▲ B未在A中出現";
            }
        }

        private void reset_Click(object sender, RoutedEventArgs e)
        {
            a.Text = b.Text = c.Text = "";
            output1.Content = "※ Output : ";
            a.Background = b.Background = c.Background = Brushes.White;
            a.Foreground = b.Foreground = c.Foreground = Brushes.Black;
            a.HorizontalContentAlignment = b.HorizontalContentAlignment = c.HorizontalContentAlignment = HorizontalAlignment.Left;
            a.IsReadOnly = b.IsReadOnly = c.IsReadOnly = false;
            button1.IsEnabled = button2.IsEnabled = button3.IsEnabled = true;
        }
    }
}