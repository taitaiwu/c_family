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

namespace WpfApp1___guess_number
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int ans1 = 0;
        private int ans2 = 0;
        private int ans3 = 0;
        private int ans4 = 0;
        private int counter = 0;
        public MainWindow()
        {
            InitializeComponent();

            Random random = new Random();
            ans1 = random.Next(1, 10);

            ans2 = random.Next(1, 10);
            while (ans2 == ans1) ans2 = random.Next(1, 10);

            ans3 = random.Next(1, 10);
            while (ans3 == ans1 || ans3 == ans2)
            {
                ans3 = random.Next(1, 10);
            }

            ans4 = random.Next(1, 10);
            ans3 = random.Next(1, 10);
            while (ans4 == ans1 || ans4 == ans2 || ans4 == ans3)
            {
                ans4 = random.Next(1, 10);
            }

            answer.Content = "Answer : " + ans1 + ans2 + ans3 + ans4;
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {

            try
            {
                int a_times = 0;
                int b_times = 0;
                string str1 = textbox1.Text.Substring(0, 1);
                string str2 = textbox1.Text.Substring(1, 1);
                string str3 = textbox1.Text.Substring(2, 1);
                string str4 = textbox1.Text.Substring(3, 1);

                if (int.Parse(str1) != ans1 || int.Parse(str2) != ans2 || int.Parse(str3) != ans3 || int.Parse(str4) != ans4)
                {
                    counter++;

                    if (int.Parse(str1) == ans1) a_times++;
                    if (int.Parse(str2) == ans2) a_times++;
                    if (int.Parse(str3) == ans3) a_times++;
                    if (int.Parse(str4) == ans4) a_times++;

                    if (int.Parse(str1) == ans2) b_times++;
                    if (int.Parse(str1) == ans3) b_times++;
                    if (int.Parse(str1) == ans4) b_times++;

                    if (int.Parse(str2) == ans1) b_times++;
                    if (int.Parse(str2) == ans3) b_times++;
                    if (int.Parse(str2) == ans4) b_times++;

                    if (int.Parse(str3) == ans1) b_times++;
                    if (int.Parse(str3) == ans2) b_times++;
                    if (int.Parse(str3) == ans4) b_times++;

                    if (int.Parse(str4) == ans1) b_times++;
                    if (int.Parse(str4) == ans2) b_times++;
                    if (int.Parse(str4) == ans3) b_times++;

                    outcome.Content = "Result : " +  a_times + "A" + b_times + "B (Hint : " + counter + ")";
                }

                else if (int.Parse(str1) == ans1 && int.Parse(str2) == ans2 && int.Parse(str3) == ans3 && int.Parse(str4) == ans4)
                {
                    outcome.Content = "Result : " + "4A0B" + "(Hint : " + counter + ")";
                }
            }

            catch 
            {
                outcome.Content = "Input format error";
            }

        }
    }
}