using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework13___max_heap
{
    public partial class Form1 : Form
    {
        TextBox[] arr = new TextBox[15];
        int num = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Paint += new PaintEventHandler(Form1_Paint);

            arr[0] = textBox3;
            arr[1] = textBox4;
            arr[2] = textBox5;
            arr[3] = textBox6;
            arr[4] = textBox7;
            arr[5] = textBox8;
            arr[6] = textBox9;
            arr[7] = textBox10;
            arr[8] = textBox11;
            arr[9] = textBox12;
            arr[10] = textBox13;
            arr[11] = textBox14;
            arr[12] = textBox15;
            arr[13] = textBox16;
            arr[14] = textBox17;
        }

        void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pen = new Pen(Color.Black, 1);
            
            g.DrawLine(pen, new Point(textBox3.Location.X + textBox3.Width / 2, textBox3.Location.Y + textBox3.Height), new Point(textBox4.Location.X + textBox4.Width / 2, textBox4.Location.Y));
            g.DrawLine(pen, new Point(textBox3.Location.X + textBox3.Width / 2, textBox3.Location.Y + textBox3.Height), new Point(textBox5.Location.X + textBox5.Width / 2, textBox5.Location.Y));

            g.DrawLine(pen, new Point(textBox4.Location.X + textBox4.Width / 2, textBox4.Location.Y + textBox4.Height), new Point(textBox6.Location.X + textBox6.Width / 2, textBox6.Location.Y));
            g.DrawLine(pen, new Point(textBox4.Location.X + textBox4.Width / 2, textBox4.Location.Y + textBox4.Height), new Point(textBox7.Location.X + textBox7.Width / 2, textBox7.Location.Y));

            g.DrawLine(pen, new Point(textBox5.Location.X + textBox5.Width / 2, textBox5.Location.Y + textBox5.Height), new Point(textBox8.Location.X + textBox8.Width / 2, textBox8.Location.Y));
            g.DrawLine(pen, new Point(textBox5.Location.X + textBox5.Width / 2, textBox5.Location.Y + textBox5.Height), new Point(textBox9.Location.X + textBox9.Width / 2, textBox9.Location.Y));

            g.DrawLine(pen, new Point(textBox6.Location.X + textBox6.Width / 2, textBox6.Location.Y + textBox6.Height), new Point(textBox10.Location.X + textBox10.Width / 2, textBox10.Location.Y));
            g.DrawLine(pen, new Point(textBox6.Location.X + textBox6.Width / 2, textBox6.Location.Y + textBox6.Height), new Point(textBox11.Location.X + textBox11.Width / 2, textBox11.Location.Y));

            g.DrawLine(pen, new Point(textBox7.Location.X + textBox7.Width / 2, textBox7.Location.Y + textBox7.Height), new Point(textBox12.Location.X + textBox12.Width / 2, textBox12.Location.Y));
            g.DrawLine(pen, new Point(textBox7.Location.X + textBox8.Width / 2, textBox7.Location.Y + textBox7.Height), new Point(textBox13.Location.X + textBox13.Width / 2, textBox13.Location.Y));
        
            g.DrawLine(pen, new Point(textBox8.Location.X + textBox8.Width / 2, textBox8.Location.Y + textBox8.Height), new Point(textBox14.Location.X + textBox14.Width / 2, textBox14.Location.Y));
            g.DrawLine(pen, new Point(textBox8.Location.X + textBox8.Width / 2, textBox8.Location.Y + textBox8.Height), new Point(textBox15.Location.X + textBox15.Width / 2, textBox15.Location.Y));

            g.DrawLine(pen, new Point(textBox9.Location.X + textBox9.Width / 2, textBox9.Location.Y + textBox9.Height), new Point(textBox16.Location.X + textBox16.Width / 2, textBox16.Location.Y));
            g.DrawLine(pen, new Point(textBox9.Location.X + textBox9.Width / 2, textBox9.Location.Y + textBox9.Height), new Point(textBox17.Location.X + textBox17.Width / 2, textBox17.Location.Y));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                textBox2.Text = "";

                if (num == 15) throw new Exception("堆積樹已滿");

                num++;
                arr[num - 1].Text = textBox1.Text;

                if (num > 1)
                {
                    int i = num - 1;

                    while (int.Parse(arr[i].Text) > int.Parse(arr[(i - 1) / 2].Text))
                    {
                        string temp = arr[(i - 1) / 2].Text;
                        arr[(i - 1) / 2].Text = arr[i].Text;
                        arr[i].Text = temp;

                        i = (i - 1) / 2;

                        if (i == 0) break;
                    }
                }
            }

            catch (Exception ex)
            {
                MessageBox.Show("輸入錯誤");
            }

            textBox1.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox2.Text = arr[0].Text;

            arr[0].Text = arr[num - 1].Text;
            arr[num - 1].Text = "";
            num--;

            int i = 0;
            while (true)
            {
                int left = i * 2 + 1;
                int right = i * 2 + 2;
                int largest = i;

                // 檢查左子節點
                if (left < num && int.Parse(arr[left].Text) > int.Parse(arr[largest].Text))
                {
                    largest = left;
                }
                // 檢查右子節點
                if (right < num && int.Parse(arr[right].Text) > int.Parse(arr[largest].Text))
                {
                    largest = right;
                }

                // 若最大值不是自己，則交換
                if (largest != i)
                {
                    string temp = arr[i].Text;
                    arr[i].Text = arr[largest].Text;
                    arr[largest].Text = temp;
                    i = largest;
                }
                else
                {
                    break;
                }
            }
        }
    }
}
