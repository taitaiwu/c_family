using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework14___shortest_path
{
    public partial class Form1 : Form
    {
        int[,] inital = new int[10, 10];
        int[,] shortest = new int[10, 10];

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Paint += new PaintEventHandler(Form1_Paint);
        }

        void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pen = new Pen(Color.Black, 1);

            g.DrawLine(pen, new Point(label1.Location.X + label1.Width / 2, label1.Location.Y + label1.Height / 2), new Point(label2.Location.X + label2.Width / 2, label2.Location.Y + label2.Height / 2));
            g.DrawLine(pen, new Point(label1.Location.X + label1.Width / 2, label1.Location.Y + label1.Height / 2), new Point(label3.Location.X + label3.Width / 2, label3.Location.Y + label3.Height / 2));
            g.DrawLine(pen, new Point(label1.Location.X + label1.Width / 2, label1.Location.Y + label1.Height / 2), new Point(label4.Location.X + label4.Width / 2, label4.Location.Y + label4.Height / 2));

            g.DrawLine(pen, new Point(label2.Location.X + label2.Width / 2, label2.Location.Y + label2.Height / 2), new Point(label4.Location.X + label4.Width / 2, label4.Location.Y + label4.Height / 2));
            g.DrawLine(pen, new Point(label2.Location.X + label2.Width / 2, label2.Location.Y + label2.Height / 2), new Point(label5.Location.X + label5.Width / 2, label5.Location.Y + label5.Height / 2));

            g.DrawLine(pen, new Point(label3.Location.X + label3.Width / 2, label3.Location.Y + label3.Height / 2), new Point(label4.Location.X + label4.Width / 2, label4.Location.Y + label4.Height / 2));
            g.DrawLine(pen, new Point(label3.Location.X + label3.Width / 2, label3.Location.Y + label3.Height / 2), new Point(label6.Location.X + label6.Width / 2, label6.Location.Y + label6.Height / 2));

            g.DrawLine(pen, new Point(label4.Location.X + label4.Width / 2, label4.Location.Y + label4.Height / 2), new Point(label5.Location.X + label5.Width / 2, label5.Location.Y + label5.Height / 2));
            g.DrawLine(pen, new Point(label4.Location.X + label4.Width / 2, label4.Location.Y + label4.Height / 2), new Point(label6.Location.X + label6.Width / 2, label6.Location.Y + label6.Height / 2));
            g.DrawLine(pen, new Point(label4.Location.X + label4.Width / 2, label4.Location.Y + label4.Height / 2), new Point(label7.Location.X + label7.Width / 2, label7.Location.Y + label7.Height / 2));

            g.DrawLine(pen, new Point(label5.Location.X + label5.Width / 2, label5.Location.Y + label5.Height / 2), new Point(label7.Location.X + label7.Width / 2, label7.Location.Y + label7.Height / 2));

            g.DrawLine(pen, new Point(label6.Location.X + label6.Width / 2, label6.Location.Y + label6.Height / 2), new Point(label7.Location.X + label7.Width / 2, label7.Location.Y + label7.Height / 2));
            g.DrawLine(pen, new Point(label6.Location.X + label6.Width / 2, label6.Location.Y + label6.Height / 2), new Point(label8.Location.X + label8.Width / 2, label8.Location.Y + label8.Height / 2));
            g.DrawLine(pen, new Point(label6.Location.X + label6.Width / 2, label6.Location.Y + label6.Height / 2), new Point(label9.Location.X + label9.Width / 2, label9.Location.Y + label9.Height / 2));

            g.DrawLine(pen, new Point(label7.Location.X + label7.Width / 2, label7.Location.Y + label7.Height / 2), new Point(label9.Location.X + label9.Width / 2, label9.Location.Y + label9.Height / 2));
            g.DrawLine(pen, new Point(label7.Location.X + label7.Width / 2, label7.Location.Y + label7.Height / 2), new Point(label10.Location.X + label10.Width / 2, label10.Location.Y + label10.Height / 2));

            g.DrawLine(pen, new Point(label8.Location.X + label8.Width / 2, label8.Location.Y + label8.Height / 2), new Point(label9.Location.X + label9.Width / 2, label9.Location.Y + label9.Height / 2));

            g.DrawLine(pen, new Point(label9.Location.X + label9.Width / 2, label9.Location.Y + label9.Height / 2), new Point(label10.Location.X + label10.Width / 2, label10.Location.Y + label10.Height / 2));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            const int INF = 1000000; // 安全的無限大
            int[,] dist = new int[10, 10];
            int[,] next = new int[10, 10];

            // 初始化距離矩陣與路徑表
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    dist[i, j] = (i == j) ? 0 : INF;
                    next[i, j] = -1;
                }
            }

            try
            {
                // 將距離資料讀入（雙向圖）
                dist[0, 1] = dist[1, 0] = int.Parse(textBox1.Text);
                dist[0, 2] = dist[2, 0] = int.Parse(textBox2.Text);
                dist[0, 3] = dist[3, 0] = int.Parse(textBox3.Text);

                dist[1, 3] = dist[3, 1] = int.Parse(textBox4.Text);
                dist[1, 4] = dist[4, 1] = int.Parse(textBox5.Text);

                dist[3, 4] = dist[4, 3] = int.Parse(textBox6.Text);
                dist[2, 3] = dist[3, 2] = int.Parse(textBox7.Text);
                dist[2, 5] = dist[5, 2] = int.Parse(textBox8.Text);

                dist[3, 5] = dist[5, 3] = int.Parse(textBox9.Text);
                dist[3, 6] = dist[6, 3] = int.Parse(textBox10.Text);

                dist[4, 6] = dist[6, 4] = int.Parse(textBox11.Text);

                dist[5, 6] = dist[6, 5] = int.Parse(textBox12.Text);
                dist[5, 7] = dist[7, 5] = int.Parse(textBox13.Text);
                dist[5, 8] = dist[8, 5] = int.Parse(textBox14.Text);

                dist[6, 8] = dist[8, 6] = int.Parse(textBox15.Text);
                dist[6, 9] = dist[9, 6] = int.Parse(textBox16.Text);

                dist[7, 8] = dist[8, 7] = int.Parse(textBox17.Text);
                dist[8, 9] = dist[9, 8] = int.Parse(textBox18.Text);
            }
            catch
            {
                MessageBox.Show("請確認所有 TextBox 都有填寫正確的整數值！");
                return;
            }

            // 初始化 next 路徑
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (dist[i, j] < INF && i != j)
                        next[i, j] = j;
                }
            }

            // Floyd-Warshall 演算法
            for (int k = 0; k < 10; k++)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (dist[i, k] < INF && dist[k, j] < INF && dist[i, k] + dist[k, j] < dist[i, j])
                        {
                            dist[i, j] = dist[i, k] + dist[k, j];
                            next[i, j] = next[i, k];
                        }
                    }
                }
            }

            // 起點與終點
            int start = textBox19.Text[0] - 'A';
            int end = textBox20.Text[0] - 'A';

            // 沒路可走
            if (dist[start, end] >= INF)
            {
                textBox21.Text = "無路徑";
                textBox22.Text = "";
                return;
            }

            // 顯示最短距離
            textBox21.Text = dist[start, end].ToString();

            // 重建路徑
            string path = "";
            int u = start;
            path += (char)(u + 'A') + "→";

            while (u != end)
            {
                u = next[u, end];
                path += (char)(u + 'A');
                if (u != end) path += "→";
            }

            textBox22.Text = path;
        }

    }
}
