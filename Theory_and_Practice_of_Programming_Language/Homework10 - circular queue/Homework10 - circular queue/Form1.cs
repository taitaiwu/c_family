using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Schema;

namespace Homework10___circular_queue
{
    public partial class Form1 : Form
    {
        TextBox[] circular_queue = new TextBox[8];
        myQueue queue = new myQueue();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            circular_queue[0] = textBox3;
            circular_queue[1] = textBox4;
            circular_queue[2] = textBox5;
            circular_queue[3] = textBox6;
            circular_queue[4] = textBox7;
            circular_queue[5] = textBox8;
            circular_queue[6] = textBox9;
            circular_queue[7] = textBox10;
            textBox11.Text = queue.getFront().ToString();
            textBox12.Text = queue.getRear().ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                int input = int.Parse(textBox1.Text);
                queue.enqueue(input);

                for (int i = 0; i < circular_queue.Length-1; i++)
                {
                    if (circular_queue[i].Text == "")
                    {
                        circular_queue[i].Text = input.ToString();
                        textBox1.Text = "";
                        textBox11.Text = queue.getFront().ToString();
                        textBox12.Text = queue.getRear().ToString();
                        break;
                    }
                }
            }

            catch 
            {
                MessageBox.Show("輸入字串格式不正確", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (queue.isEmpty())
                MessageBox.Show("沒有資料", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            else
            {
                int output = queue.dequeue();
                textBox1.Text = "";
                textBox11.Text = queue.getFront().ToString();
                textBox12.Text = queue.getRear().ToString();
                for (int i = 0; i < circular_queue.Length; i++)
                {
                    if (circular_queue[i].Text == "")
                    {
                        circular_queue[i - 1].Text = "";
                        textBox2.Text = output.ToString();
                        break;
                    }
                }
            }
        }
    }

    class myQueue
    {
        const int MAX = 8;
        public int[] queue = new int[MAX];
        public int front = MAX-1, rear = MAX-1;

        public void enqueue(int item)
        {
            if (((rear + 1) % MAX) == front)
                MessageBox.Show("空間已滿", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);

            else
            {
                rear = (rear + 1) % MAX;
                queue[rear] = item;
            }
        }

        public bool isEmpty()
        {
            if (front == rear)
                return true;
            else
                return false;
        }

        public int dequeue()
        {
            front = (front + 1) % MAX;
            return queue[front];
        }

        public int getFront()
        {
            return front;
        }

        public int getRear()
        {
            return rear;
        }
    }
}
