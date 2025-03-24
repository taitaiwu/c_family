using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;


namespace Homework4___data_mining
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // textbox1
            openFileDialog1.Filter = "純文字檔案(*.txt)|*.txt";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                StreamReader sr = new StreamReader(openFileDialog1.FileName);
                string[,] record = new string[50, 101];
                int recordNo = 0;
                int[] itemNum = new int[50];
                string[] input = null;

                textBox1.Text = "客戶 購買商品代號\r\n";

                while (sr.Peek() >= 0)
                {
                    input = sr.ReadLine().Split();
                    itemNum[recordNo] = input.Length;

                    for (int i = 0; i < input.Length; i++)
                    {
                        record[recordNo, i] = input[i];
                        textBox1.Text += input[i] + " ";
                    }

                    textBox1.Text += "\r\n";
                    recordNo++;
                }

                // textbox2
                textBox2.Text = "客戶 相似客戶 推薦商品代號\r\n";

                for (int i = 0; i < recordNo; i++)
                {
                    textBox2.Text += record[i, 0] + " "; // 輸出客戶 ID

                    int[] same = new int[50]; // 記錄與其他客戶的相似度

                    // 計算相似度
                    for (int j = 0; j < itemNum[i]; j++)
                    {
                        for (int k = 0; k < recordNo; k++)
                        {
                            if (k == i) continue; // 跳過自己

                            for (int l = 0; l < itemNum[k]; l++)
                            {
                                if (record[i, j] == record[k, l])
                                {
                                    same[k] += 1;
                                }
                            }
                        }
                    }

                    // 找出最相似的客戶
                    List<int> maxIndices = new List<int>();
                    int maxSimilarity = 0;

                    for (int x = 0; x < recordNo; x++)
                    {
                        if (same[x] > maxSimilarity)
                        {
                            maxSimilarity = same[x];
                            maxIndices.Clear();
                            maxIndices.Add(x);
                        }
                        else if (same[x] == maxSimilarity && maxSimilarity > 0)
                        {
                            maxIndices.Add(x);
                        }
                    }

                    // 顯示相似客戶
                    if (maxIndices.Count > 0)
                    {
                        textBox2.Text += "( ";
                        foreach (int index in maxIndices)
                        {
                            textBox2.Text += record[index, 0] + " ";
                        }
                        textBox2.Text += ") ";
                    }

                    // 取得推薦商品 (去掉已購買的商品)
                    HashSet<string> purchasedItems = new HashSet<string>(); // 記錄當前客戶已購買的商品
                    HashSet<string> recommendedItems = new HashSet<string>(); // 推薦商品 (去重)

                    // 記錄該客戶已購買的商品
                    for (int j = 0; j < itemNum[i]; j++)
                    {
                        purchasedItems.Add(record[i, j]);
                    }

                    // 從最相似的客戶中獲取推薦商品
                    foreach (int index in maxIndices)
                    {
                        for (int j = 1; j < itemNum[index]; j++) // 注意: j 從 1 開始，避免推薦客戶 ID
                        {
                            string item = record[index, j];

                            if (!purchasedItems.Contains(item)) // 只推薦該客戶沒買過的商品
                            {
                                recommendedItems.Add(item);
                            }
                        }
                    }

                    // 顯示推薦商品
                    if (recommendedItems.Count > 0)
                    {
                        textBox2.Text += " ";
                        foreach (string item in recommendedItems)
                        {
                            textBox2.Text += item + " ";
                        }
                    }

                    textBox2.Text += "\r\n";
                }
            }

        }
    }
}
