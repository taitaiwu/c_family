using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework11___singly_linked_list
{
    public partial class Form1 : Form
    {
        private node head;

        public Form1()
        {
            InitializeComponent();
            textBox2.Text = "head -> null";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                int input = int.Parse(textBox1.Text);
                node n = new node(input);

                node check = head;
                while (check != null)
                {
                    if (check.getData() == input)
                    {
                        MessageBox.Show("資料" + input + "重複", "重複資料", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }
                    check = check.getNext();
                }

                if (head == null || head.getData() > input)
                {
                    n.setNext(head);
                    head = n;
                }
                else
                {
                    node ptr1 = head;
                    node ptr2 = head.getNext();

                    while (ptr2 != null && ptr2.getData() <= input)
                    {
                        ptr1 = ptr2;
                        ptr2 = ptr2.getNext();
                    }

                    ptr1.setNext(n);
                    n.setNext(ptr2);
                }

                node curr = head;
                textBox2.Text = "head -> ";
                while (curr != null)
                {
                    textBox2.Text += curr.getData() + " -> ";
                    curr = curr.getNext();
                }
                textBox2.Text += "null";
            }
            catch (Exception)
            {
                MessageBox.Show("輸入字串格式不正確", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int input = int.Parse(textBox1.Text);

                // 情況一：head 就是要刪的節點
                if (head != null && head.getData() == input)
                {
                    head = head.getNext();
                }
                else
                {
                    node ptr1 = head;
                    node ptr2 = head?.getNext();

                    bool deleted = false;

                    while (ptr2 != null)
                    {
                        if (ptr2.getData() == input)
                        {
                            ptr1.setNext(ptr2.getNext());
                            deleted = true;
                            break;
                        }
                        ptr1 = ptr2;
                        ptr2 = ptr2.getNext();
                    }

                    if (!deleted)
                    {
                        MessageBox.Show("串列中沒有 " + input , "刪除失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }
                }

                // 更新顯示
                node curr = head;
                textBox2.Text = "head -> ";
                while (curr != null)
                {
                    textBox2.Text += curr.getData() + " -> ";
                    curr = curr.getNext();
                }
                textBox2.Text += "null";
            }
            catch (FormatException)
            {
                MessageBox.Show("請輸入正確的整數格式", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

    }

    class node
    {
        int data;
        node next;

        public node(int n)
        {
            data = n;
            next = null;
        }

        public int getData()
        {
            return data;
        }

        public node getNext()
        {
            return next;
        }

        public void setData(int n)
        {
            data = n;
        }

        public void setNext(node n)
        {
            next = n;
        }
    }
}
