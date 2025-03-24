using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Xps.Serialization;

namespace Homework4___booking_system
{
    /// <summary>
    /// Booking_window.xaml 的互動邏輯
    /// </summary>
    public partial class Booking_window : Window
    {
        public event EventHandler<CartDataPassedEventArgs> CartDataPassed;

        private Dictionary<string, List<string>> English_name;
        private Dictionary<string, List<string>> movie_actor;
        private Choose_seat choose_Seat;

        private int room = 0;
        private double ticket = 0;
        private int food = 0;
        private int serial = 0;
        private string[] info = new string[2];
        private string[] food_kind = new string[100];
        private bool check = true;

        public Booking_window(string movie_name, string movie_date, string movie_time)
        {
            InitializeComponent();
            InitializeData();

            string appStartPath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName);
            string filename = movie_name;

            Uri uri = new Uri(appStartPath + @"/movie/" + movie_name + ".jpg", UriKind.Absolute);
            BitmapImage bitmapImage = new BitmapImage(uri);
            movie.Source = bitmapImage;

            title.Content = movie_name;
            if (English_name.ContainsKey(movie_name)) eng_title.Content = string.Join(", ", English_name[movie_name]);

            if (title.Content.ToString().Length > 10) title.FontSize = 40;
            else if (title.Content.ToString().Length < 5) title.FontSize = 55;

            if (eng_title.Content.ToString().Length > 25) eng_title.FontSize = 20;
            else if (eng_title.Content.ToString().Length < 10) eng_title.FontSize = 40;

            information.Content = "🕑 " + movie_date + " " + movie_time;

            if (movie_actor.ContainsKey(movie_name))
            {
                if (movie_name == "八戒：決戰未來" || movie_name == "湯姆貓與傑利鼠" || movie_name == "功夫熊貓4" || movie_name == "劇場版 排球少年!! 垃圾場的決戰" || movie_name == "機動戰士鋼彈SEED FREEDOM" || movie_name == "特別總集篇 名偵探柯南 VS. 怪盜基德" || movie_name == "BanG Dream! It's MyGo!!!!!") detail.Content = "配音 : " + string.Join(", ", movie_actor[movie_name]);

                else detail.Content = "演員 : " + string.Join(", ", movie_actor[movie_name]);
            }
        }

        private void InitializeData()
        {
            English_name = new Dictionary<string, List<string>>()
            {
                {"夏日的檸檬草", new List<string>() {"I AM THE SCERET IN YOUR HEART"}},
                {"八戒：決戰未來", new List<string>() {"PIGSY"}},
                {"環南時候", new List<string>() {"THE TIME OF HUAN NAN"}},
                {"(真)新的一天", new List<string>() {"FISH MEMORIES"}},
                {"我在這裡等你", new List<string>() {"A BALLOONS LANDING"}},
                {"青春18×2 通往有你的旅程", new List<string>() {"18x2 BEYOND YOUTHFUL DAYS"}},
                {"再見，李可樂", new List<string>() {"SO LONG FOR LOVE"}},
                {"照明商店", new List<string>() {"LOVE LIFE NIGHT"}},
                {"野孩子", new List<string>() {"STAND BY ME"}},
                {"熱辣滾燙", new List<string>() {"YOLO"}},
                {"第二十條", new List<string>() {"ARTICLE 20"}},
                {"這麼多年", new List<string>() {"ALL THE SO YEARS"}},
                {"念念相忘", new List<string>() {"JUST FOR MEETING YOU" }},
                {"湯姆貓與傑利鼠", new List<string>() {"TOM & JERRY"}},
                {"腦筋急轉彎2", new List<string>() {"INSIDE OUT 2"}},
                {"功夫熊貓4", new List<string>() {"KUNG FU PANDA 4"}},
                {"猩球崛起：王國誕生", new List<string>() {"KINGDOM OF THE PLANET OF THE APES"}},
                {"當殺手戀愛時", new List<string>() {"HITMAN"}},
                {"怒火狂猴", new List<string>() {"MONKEY MAN"}},
                {"BanG Dream! It's MyGo!!!!!", new List<string>(){ "BanG Dream! It's MyGo!!!!!" }},
                {"劇場版 排球少年!! 垃圾場的決戰", new List<string>() {"HAIKYU THE DUMPSTER BATTLE"}},
                {"機動戰士鋼彈SEED FREEDOM", new List<string>() {"MOBILE SUIT GUNDAM SEED FREEDOM"}},
                {"特別總集篇 名偵探柯南 VS. 怪盜基德", new List<string>() { "DETECTIVE CONAN COMPILATION FILM DETECTIVE"}},
                {"那日清晨真令人感到空虛", new List<string>() {"WHEN MORNING COMES I FEEL EMPTY"}},
                {"她死了", new List<string>() {"FOLLOWING"}},
                {"神鬼對決", new List<string>() {"TROLL FACTORY"}}
            };

            movie_actor = new Dictionary<string, List<string>>()
            {
                {"夏日的檸檬草", new List<string>() {"曹佑寧、羅峻碩、李沐"}},
                {"八戒：決戰未來", new List<string>() {"許光漢、邵雨薇、魏如萱"}},
                {"環南時候", new List<string>() {"宋柏緯、初孟軒、夏騰宏、王渝屏"}},
                {"(真)新的一天", new List<string>() {"李銘忠、王碩瀚、虹茜"}},
                {"我在這裡等你", new List<string>() {"范少勳、劉俊謙"}},
                {"青春18×2 通往有你的旅程", new List<string>() {"許光漢、清原果耶"}},
                {"再見，李可樂", new List<string>() {"閻妮、譚松韻"}},
                {"照明商店", new List<string>() {"章若楠、白宇帆"}},
                {"野孩子", new List<string>() {"王俊凱、鄧家佳、陳永勝、潘斌龍"}},
                {"熱辣滾燙", new List<string>() {"賈玲、雷佳音、楊紫、李雪琴"}},
                {"第二十條", new List<string>() {"雷佳音、馬麗、趙麗穎、高葉、劉耀文"}},
                {"這麼多年", new List<string>() {"張新成、孫千"}},
                {"念念相忘", new List<string>() {"宋威龍、劉浩存" }},
                {"湯姆貓與傑利鼠", new List<string>() {"克蘿伊·摩蕾茲、麥可·潘納"}},
                {"腦筋急轉彎2", new List<string>() {"愛咪·波勒、菲利斯·史密斯"}},
                {"功夫熊貓4", new List<string>() {"傑克·布萊克、奧卡菲娜"}},
                {"猩球崛起：王國誕生", new List<string>() {"歐文·提格、芙蕾雅·艾倫"}},
                {"當殺手戀愛時", new List<string>() {"格倫·鮑威爾、安卓·亞霍娜"}},
                {"怒火狂猴", new List<string>() {"戴夫·帕托、沙托·科普利"}},
                {"BanG Dream! It's MyGo!!!!!", new List<string>() {"羊宮妃那、立石凜、青木陽菜、小日向美香、林鼓子"}},
                {"劇場版 排球少年!! 垃圾場的決戰", new List<string>() {"村瀨步、石川界人"}},
                {"機動戰士鋼彈SEED FREEDOM", new List<string>() {"保志總一朗、田中理惠"}},
                {"特別總集篇 名偵探柯南 VS. 怪盜基德", new List<string>() { "高山南、山口勝平"}},
                {"那日清晨真令人感到空虛", new List<string>() {"唐田英里佳、芋生悠"}},
                {"她死了", new List<string>() {"卞約漢、申惠善、李伊"}},
                {"神鬼對決", new List<string>() {"錫久、金聖喆、金東輝、洪慶"}}
            };
        }

        private void room_checked(object sender, RoutedEventArgs e)
        {
            RadioButton radioButton = sender as RadioButton;

            string content = "";

            if (radioButton.IsChecked == true) content = radioButton.Content.ToString();

            int index = content.IndexOf("$");
            content = content.Substring(index + 1, content.Length - index - 1);
            room = int.Parse(content);
            string room_name = radioButton.Content.ToString().Substring(0, index-3);
            info[0] = room_name; 
        }

        private void ticket_checked(object sender, RoutedEventArgs e)
        {
            RadioButton radioButton = sender as RadioButton;
            CheckBox checkBox = sender as CheckBox;

            if (special != null)
            {
                special.IsEnabled = false;
                special.IsChecked = false;
            }
            
            if (vip != null)
            {
                vip.IsEnabled = false;
                vip.IsChecked = false;
            }

            if (normal.IsChecked == true) ticket =  1;
            else if (child.IsChecked == true) ticket = 0.6;
            else if (student.IsChecked == true) ticket = 0.9;
            else if (nqu_shop.IsChecked == true)
            {
                ticket = 0.85;
                vip.IsEnabled = true;
                special.IsEnabled = false;
                special.IsChecked = false;  
            }
            else if (nqu.IsChecked == true || chsc.IsChecked == true)
            {
                ticket = 0.8;
                special.IsEnabled = true;
                vip.IsEnabled = false;
                vip.IsChecked = false;
            }

            if (radioButton.IsChecked == true)
            {
                int index = radioButton.Content.ToString().IndexOf(" ");
                info[1] = radioButton.Content.ToString().Substring(0, index);
            }
        }

        private void food_checked(object sender, RoutedEventArgs e)
        {
            CheckBox checkBox = sender as CheckBox;
            string content = "";

            if (checkBox.IsChecked == true) content = checkBox.Content.ToString();

            int index1 = content.IndexOf("$");
            content = content.Substring(index1 + 1, content.Length - index1 - 1);
            food = int.Parse(content);

            int index2 = checkBox.Content.ToString().IndexOf(" ");

            if (checkBox.IsChecked != false)
            {
                food_kind[serial] = checkBox.Content.ToString().Substring(0, index2);
                serial++;
            }
        }

        private void food_uncheck(object sender, RoutedEventArgs e)
        {
            if (check)
            {
                CheckBox checkBox = sender as CheckBox;

                string str = checkBox.Content.ToString().Substring(0, checkBox.Content.ToString().IndexOf(" "));
                int index = Array.IndexOf(food_kind, str);
                
                if (index != -1)
                {
                    List<string> kind_list = food_kind.ToList();
                    kind_list.RemoveAt(index);
                    food_kind = kind_list.ToArray();
                    serial--;
                }
            }

            else check = true;
        }
        private void num_click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;
            int number = int.Parse(num.Content.ToString());

            if (button == increase && number < 10) number++;
            else if (button == decrease && number > 1) number--;

            num.Content = number.ToString();
        }

        private void add_Click(object sender, RoutedEventArgs e)
        {
            int temp = int.Parse(num.Content.ToString());


            Choose_seat choose_Seat = new Choose_seat(title.Content.ToString(), info[0], information.Content.ToString(), temp);
            choose_Seat.datapass += Choose_Seat_datapass;
            choose_Seat.Closed += choose_Seat_Closed;

            if (choose_Seat != null) add.IsEnabled = delete.IsEnabled = clear.IsEnabled = back.IsEnabled = false;
            else add.IsEnabled = delete.IsEnabled = clear.IsEnabled = back.IsEnabled = true;

            choose_Seat.Show();

            cart.Items.Add("☑" + info[0].ToString() + " " + info[1].ToString() + "×" + temp + "  $" + (int)Math.Round(room * ticket) * temp);
            
            for (int i = 0; i < serial; i++)
            {
                if (food_kind[i] != "") cart.Items.Add("   +" + food_kind[i].ToString() + "×" + temp + "  $" + food * temp);
                else break;
            }

            cart.Items.Add("");

            calcular();

            serial = 0;
            Array.Clear(food_kind , 0, food_kind.Length);
            num.Content = "1";

            check = false;
            checkbox_uncheck();
        }

        private void choose_Seat_Closed(object? sender, EventArgs e)
        {
            choose_Seat = null;
            add.IsEnabled = delete.IsEnabled = clear.IsEnabled = back.IsEnabled = true;
        }

        private void Choose_Seat_datapass(object? sender, DataPassedEventArgs e)
        {
            string str = "";
            int temp1 = 0;
            int temp2 = 0;

            if (e.Choices.Count > 0)
            {
                for (int i = 0; i < e.Choices.Count; i++)
                {
                    str += e.Choices[i].ToString() + " ";
                }

                cart.Items.RemoveAt(cart.Items.Count - 1);
                cart.Items.Add("  →座位:" + str + " $0");
                cart.Items.Add("");
            }

            else
            {
                for (int i = cart.Items.Count - 1 ; i >= 0; i--)
                {
                    int index1 = cart.Items[i].ToString().IndexOf("☑");

                    if (index1 != -1)
                    {
                        temp1 = i;
                        break;
                    }
                }

                for (int i = temp1; i < cart.Items.Count; i++)
                {
                    int index2 = cart.Items[i].ToString().IndexOf("$");

                    if (index2 == -1)
                    {
                        temp2 = i;
                        break;
                    }
                }

                for (int i = temp2; i >= temp1;  i--)
                {
                    cart.Items.RemoveAt(i);
                }

                calcular();
            }
        }

        private void checkbox_uncheck ()
        {
            L_cola.IsChecked = M_cola.IsChecked = S_cola.IsChecked 
                = L_popcorn.IsChecked = M_popcorn.IsChecked = S_popcorn.IsChecked 
                = hotdog.IsChecked = gina.IsChecked 
                = special.IsChecked = vip.IsChecked = nor_web.IsChecked 
                = false;
        }

        private void delete_click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;
            int temp = 0;

            if (button == delete && cart != null && cart.SelectedItem != null)
            {
                int index1 = cart.SelectedItem.ToString().IndexOf("+");
                int index2 = cart.SelectedItem.ToString().IndexOf("→");
                int temp_select = cart.SelectedIndex;

                if (cart.SelectedItem != "" && index2 == -1)
                {
                    if (index1 != -1) cart.Items.Remove(cart.SelectedItem);
                    else
                    {
                        for (int i = cart.SelectedIndex; i < cart.Items.Count; i++)
                        {
                            if (cart.Items[i] == "")
                            {
                                temp = i;
                                break;
                            }
                        }

                        for (int i = temp; i >= temp_select; i--)
                        {
                            cart.Items.RemoveAt(i);
                        }
                    }
                }

                calcular();
            }

            else if (button == clear)
            {
                cart.Items.Clear();
                calcular();
            }
        }

        private void calcular()
        {
            int total = 0;

            for (int i = 0; i < cart.Items.Count; i++)
            {
                if (cart.Items[i] != "")
                {
                    int index = cart.Items[i].ToString().IndexOf("$");
                    total += int.Parse(cart.Items[i].ToString().Substring(index + 1, cart.Items[i].ToString().Length - index - 1));
                }
            }

            price.Content = "※ 金額:" + total.ToString();
        }

        private void back_Click(object sender, RoutedEventArgs e)
        {
            List<string> list = new List<string>();

            int index; ;

            for (int i = 0;i < cart.Items.Count;i++)
            {
                index = cart.Items[i].ToString().IndexOf("☑");

                if (index != -1) list.Add(title.Content.ToString());

                list.Add(cart.Items[i].ToString());
            }

            CartDataPassed?.Invoke(this, new CartDataPassedEventArgs(list));

            this.Close();
        }
    }

    public class CartDataPassedEventArgs : EventArgs
    {
        public List<string> Items { get; set; }

        public CartDataPassedEventArgs(List<string> items)
        {
            Items = items;
        }
    }
}
