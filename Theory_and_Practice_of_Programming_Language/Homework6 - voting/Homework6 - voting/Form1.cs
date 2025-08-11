using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework6___voting
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "二元檔案(*.dat) | *.dat";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                FileStream fs = new FileStream(openFileDialog1.FileName, FileMode.Open);
                BinaryReader br = new BinaryReader(fs);
                textBox1.Text = "第1回合 : \r\n";

                int cn = br.ReadInt32();
                int bn = br.ReadInt32();
                int[,] ballot = new int[bn, cn];
                int[] count = new int[cn + 1];
                bool[] remove = new bool[cn + 1];

                // 讀取選票
                for (int i = 0; i < bn; i++)
                {
                    for (int j = 0; j < cn; j++)
                    {
                        ballot[i, j] = br.ReadInt32();
                    }
                }

                // 初始化
                int round = 1;
                bool winnerFound = false;  // 控制迴圈結束
                while (!winnerFound)
                {
                    textBox1.Text += $"\r\n第 {round} 回合:\r\n";

                    // 重新計算得票數
                    Array.Clear(count, 0, count.Length);
                    for (int i = 0; i < bn; i++)
                    {
                        int candidate = ballot[i, 0]; // 每張票的第一順位
                        if (candidate > 0) count[candidate]++;
                    }

                    // 檢查是否有過半當選者
                    int max = 0;
                    for (int i = 1; i <= cn; i++)
                    {
                        if (!remove[i] && count[i] > max)
                            max = count[i];
                    }

                    if (max > (bn / 2))
                    {
                        for (int i = 1; i <= cn; i++)
                        {
                            if (count[i] == max)
                            {
                                textBox1.Text += $"號碼 {i} 號候選人過半數當選\r\n";
                                winnerFound = true;
                                break;
                            }
                        }
                        break;
                    }

                    // 找到最低票數
                    int min = int.MaxValue;
                    for (int i = 1; i <= cn; i++)
                    {
                        if (!remove[i] && count[i] > 0 && count[i] < min)
                            min = count[i];
                    }

                    // 標記要淘汰的候選人
                    for (int i = 1; i <= cn; i++)
                    {
                        if (count[i] == min)
                        {
                            remove[i] = true;
                            textBox1.Text += $"號碼 {i} 號候選人 ";
                        }
                    }
                    textBox1.Text += "本回合最低票被淘汰\r\n";

                    // 檢查是否所有候選人都被淘汰
                    bool allEliminated = true;
                    for (int i = 1; i <= cn; i++)
                    {
                        if (!remove[i])
                        {
                            allEliminated = false;
                            break;
                        }
                    }
                    if (allEliminated)
                    {
                        textBox1.Text += $"\r\n第 {round+1} 回合:\r\n";
                        textBox1.Text += "無法決定當選者";
                        break;
                    }

                    // 淘汰候選人，把票移除
                    for (int i = 0; i < bn; i++)
                    {
                        for (int j = 0; j < cn; j++)
                        {
                            if (remove[ballot[i, j]])
                                ballot[i, j] = 0;
                        }
                    }

                    // 重新排序選票，把 `0` 移到最後
                    for (int i = 0; i < bn; i++)
                    {
                        int zero = 0;
                        for (int j = 0; j < cn; j++)
                        {
                            if (ballot[i, j] != 0)
                            {
                                (ballot[i, j], ballot[i, zero]) = (ballot[i, zero], ballot[i, j]);
                                zero++;
                            }
                        }
                    }

                    round++;
                }
            }
        }

    }
}

/* for (int i = 0; i < bn; i++)
                    {
                        for (int j = 0; j < cn; j++)
                        {
                            textBox1.Text += ballot[i, j];
                        }

                        textBox1.Text += "\r\n";
                    }*/