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

namespace Homework4___booking_system
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int filename1 = 1;
        private int filename2 = 1;
        private Dictionary<string, List<string>> moviename_dict;
        private Booking_window booking_Window;

        public MainWindow()
        {
            InitializeComponent();
            InitializData();
            kind_comboboxitem();

            WindowStartupLocation = WindowStartupLocation.CenterScreen;

            DispatcherTimer dispatcherTimer = new DispatcherTimer();
            dispatcherTimer.Tick += new EventHandler(dispatcherTimer_Tick);
            dispatcherTimer.Interval = TimeSpan.FromSeconds(3);
            dispatcherTimer.Start();

        }

        private void InitializData()
        {
            moviename_dict = new Dictionary<string, List<string>>()
            {
                {"臺灣電影", new List<string> {"夏日的檸檬草", "八戒：決戰未來", "環南時候", "(真)新的一天", "我在這裡等你", "青春18×2 通往有你的旅程"}},
                {"中國電影", new List<string> {"再見，李可樂", "照明商店", "野孩子", "熱辣滾燙", "第二十條", "這麼多年", "念念相忘"}},
                {"歐美電影", new List<string> {"湯姆貓與傑利鼠", "腦筋急轉彎2", "功夫熊貓4", "猩球崛起：王國誕生", "當殺手戀愛時", "怒火狂猴"}},
                {"日本電影", new List<string> { "BanG Dream! It's MyGo!!!!!", "劇場版 排球少年!! 垃圾場的決戰", "機動戰士鋼彈SEED FREEDOM", "特別總集篇 名偵探柯南 VS. 怪盜基德", "那日清晨真令人感到空虛"}},
                {"韓國電影", new List<string> {"她死了", "神鬼對決", "犯罪都市4"}}
            };
        }

        private void kind_comboboxitem()
        {
            kind.ItemsSource = moviename_dict.Keys;
        }

        private void kind_selection(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            if (kind.SelectedItem != null)
            {
                string kind_select = kind.SelectedItem.ToString();
                name_comboboxitem(kind_select);
            }
        }

        private void name_comboboxitem(string kind_select)
        {
            if (moviename_dict.ContainsKey(kind_select))
            {
                name.ItemsSource = moviename_dict[kind_select];
            }
        }

        private void dispatcherTimer_Tick(object? sender, EventArgs e)
        {

            filename1++;
            if (filename1 > 6) filename1 = 1;

            filename2++;
            if (filename2 > 2) filename2 = 1;

            string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);

            Uri uri1 = new Uri(appStartPath + @"/marquee/" + filename1 + ".jpg", UriKind.Absolute);
            Uri uri2 = new Uri(appStartPath + @"/news/" + filename2 + ".jpg", UriKind.Absolute);

            BitmapImage bitmapImage1 = new BitmapImage(uri1);
            BitmapImage bitmapImage2 = new BitmapImage(uri2);

            marquee.Source = bitmapImage1;
            news.Source = bitmapImage2;
        }

        private void book_Click(object sender, RoutedEventArgs e)
        {
            if (kind.SelectedItem != null && name.SelectedItem != null && date.SelectedItem != null && time.SelectedItem != null)
            {
                string movie_name = name.Text.ToString();
                string movie_date = date.Text.ToString();
                string movie_time = time.Text.ToString();

                Booking_window booking_Window = new Booking_window(movie_name, movie_date, movie_time);
                booking_Window.CartDataPassed += Booking_Window_CartDataPassed;
                booking_Window.Closed += Booking_window_Close;

                if (booking_Window != null) book.IsEnabled =  delete.IsEnabled = clear.IsEnabled = pay.IsEnabled = false;
                else book.IsEnabled = true;

                booking_Window.Show();
            }

            else
            {
                string str = "尚未選擇:";
                if (kind.SelectedItem == null) str += "電影種類 ";
                if (name.SelectedItem == null) str += "電影名稱 ";
                if (date.SelectedItem == null) str += "日期 ";
                if (time.SelectedItem == null) str += "時間 ";
                MessageBox.Show(str);
            }
        }

        private void Booking_window_Close(object? sender, EventArgs e)
        {
            booking_Window = null;
            book.IsEnabled = delete.IsEnabled = clear.IsEnabled = pay.IsEnabled = true ;
        }

        private void Booking_Window_CartDataPassed(object? sender, CartDataPassedEventArgs e)
        {
            for (int i = 0; i < e.Items.Count; i++)
            {
                listbox1.Items.Add(e.Items[i].ToString());
            }

            calcular();
        }

        private void delete_Click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;
            int temp = 0;

            if (button == delete && listbox1 != null && listbox1.SelectedItem != null)
            {
                int index1 = listbox1.SelectedItem.ToString().IndexOf("+");
                int index2 = listbox1.SelectedItem.ToString().IndexOf("→");
                int index3 = listbox1.SelectedItem.ToString().IndexOf("☑");
                int temp_select = listbox1.SelectedIndex;

                if (listbox1.SelectedItem != "" && index2 == -1)
                {
                    if (index1 != -1) listbox1.Items.Remove(listbox1.SelectedItem);
                    else
                    {
                        for (int i = listbox1.SelectedIndex; i < listbox1.Items.Count; i++)
                        {
                            if (listbox1.Items[i] == "")
                            {
                                temp = i;
                                break;
                            }
                        }

                        for (int i = temp; i >= temp_select; i--)
                        {
                            listbox1.Items.RemoveAt(i);
                        }

                        if (index3 != -1) listbox1.Items.RemoveAt(temp_select - 1);
                    }
                }
            }

            calcular();
        }

        private void clear_Click(object sender, RoutedEventArgs e)
        {
            listbox1.Items.Clear();
            calcular();
        }

        private void pay_Click(object sender, RoutedEventArgs e)
        {
            if (listbox1.Items.Count != 0)
            {
                MessageBox.Show("程式體驗結束，感謝您的體驗\nP.S可能有一些小bug 拜託不要扣我分");
                this.Close();
            }

            else MessageBox.Show("您尚未訂購任何電影票");
        }

        private void calcular()
        {
            int total = 0;

            for (int i = 0; i < listbox1.Items.Count; i++)
            {
                if (listbox1.Items[i] != "")
                {
                    int index = listbox1.Items[i].ToString().IndexOf("$");
                    
                    if (index != -1) total += int.Parse(listbox1.Items[i].ToString().Substring(index + 1, listbox1.Items[i].ToString().Length - index - 1));
                }
            }

            cart.Header = "我的購物車 $" + total.ToString();
        }

    }
}