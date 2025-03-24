using System;
using System.Collections.Generic;
using System.Linq;
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

namespace Homework4___booking_system
{
    /// <summary>
    /// Choose_seat.xaml 的互動邏輯
    /// </summary>

    public partial class Choose_seat : Window
    {
        public event EventHandler<DataPassedEventArgs> datapass;

        private int choose_times = 0;
        private int choose_max = 0;
        private int row = 8;
        private int col = 15;
        private List<string> choice = new List<string>();

        public Choose_seat(string movie_name, string room_name, string movie_time, int ticket_num)
        {
            InitializeComponent();

            title.Content = movie_name;
            if (movie_name.Length > 10) title.FontSize = 30;
            seat_num.Content = "票數 : " + ticket_num + " 張 ; 已選 : " + choose_times + " 張";
            time.Content = movie_time;
            room.Content = "📽️ " + room_name + "影廳";

            createseat();
            choose_max = ticket_num;
        }

        private void createseat()
        {
            StackPanel stackPanel1 = new StackPanel();
            stackPanel1.Orientation = Orientation.Vertical; 

            for (int i = 0; i < row; i++)
            {
                StackPanel stackPanel2 = new StackPanel();
                stackPanel2.Orientation = Orientation.Horizontal;

                Label label = new Label();
                label.Content = $"{(char)('A' + i)}";
                label.HorizontalContentAlignment = HorizontalAlignment.Center;
                label.FontSize = 20;
                label.Width = 30;
                stackPanel2.Children.Add(label);

                for (int j = 0; j < col; j++)
                {
                    Button seatbutton = new Button();
                    seatbutton.Name = $"{(char)('A' + i)}{j + 1}";
                    seatbutton.Content = $"{j + 1}";
                    seatbutton.Width = 40;
                    seatbutton.Height = 40;
                    seatbutton.FontSize = 20;
                    seatbutton.Background = Brushes.White;
                    seatbutton.Click += Seatbutton_Click;

                    if (j != 0 && j%5 == 0) seatbutton.Margin = new Thickness(10, 1, 1, 1);
                    else seatbutton.Margin = new Thickness(1);

                    stackPanel2.Children.Add(seatbutton);
                }
                stackPanel1.Children.Add(stackPanel2);
            }
            seat.Children.Add(stackPanel1);
        }

        private void Seatbutton_Click(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;

            Random random = new Random();


            if (button.Background == Brushes.White && choose_times < choose_max)
            {
                button.Background = Brushes.SkyBlue;
                choose_times++;
                choice.Add(button.Name.ToString());
            }

            else if (button.Background == Brushes.SkyBlue)
            {
                button.Background = Brushes.White;
                choose_times--;
                choice.Remove(button.Name.ToString());
            }

            seat_num.Content = "票數 : " + choose_max + "張 ; 已選 : " + choose_times + " 張" ;
        }

        private void cancel_Click(object sender, RoutedEventArgs e)
        {
            choice.Clear();
            datapass?.Invoke(this, new DataPassedEventArgs(choice));
            this.Close();
        }


        private void again_Click(object sender, RoutedEventArgs e)
        {
            seat.Children.Clear();
            createseat();
            choose_times = 0;
            seat_num.Content = "票數 : " + choose_max + " 張 ; 已選 : " + choose_times + " 張";
        }

        private void sent_Click(object sender, RoutedEventArgs e)
        {
            if (choose_times == choose_max)
            {
                datapass?.Invoke(this, new DataPassedEventArgs(choice));
                this.Close();
            }

            else MessageBox.Show("選位尚未完成\n" + "▲尚未選擇:" + (choose_max - choose_times) + "位");
        }
    }

    public class DataPassedEventArgs : EventArgs
    {
        public List<string> Choices { get; }

        public DataPassedEventArgs(List<string>choices)
        {
            Choices = choices;
        }
    }
}

