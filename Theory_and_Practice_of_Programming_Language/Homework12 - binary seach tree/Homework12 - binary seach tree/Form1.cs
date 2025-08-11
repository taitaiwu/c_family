using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework12___binary_seach_tree
{
    public partial class Form1 : Form
    {
        node root = new node(0);

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int n = int.Parse(textBox1.Text);

            node ptr1 = root;
            node ptr2 = root.getLeft();
            node x = new node(n);

            textBox2.Text = "";

            if (ptr2 == null) root.setLeft(x);

            while (ptr2 != null)
            {
                if (ptr2.getData() == n)
                {
                    MessageBox.Show("資料" + textBox1.Text + "已存在", "新增失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    textBox2.Text = "";
                    inorder(root.getLeft());
                    return;
                }

                ptr1 = ptr2;

                if (n < ptr2.getData()) ptr2 = ptr2.getLeft();
                else if(n > ptr2.getData()) ptr2 = ptr2.getRight();
            }

            if (n < ptr1.getData()) ptr1.setLeft(x);
            else if (n > ptr1.getData()) ptr1.setRight(x);

            inorder(root.getLeft());
            textBox1.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int n = int.Parse(textBox1.Text);

            node ptr1 = root;
            node ptr2 = root.getLeft();

            textBox2.Text = "";

            while (ptr2 != null)
            {
                if (ptr2.getData() == n) break;

                ptr1 = ptr2;

                if (n < ptr2.getData()) ptr2 = ptr2.getLeft();
                else ptr2 = ptr2.getRight();
            }

            if (ptr2 == null) MessageBox.Show("資料" + textBox1.Text + "不存在", "刪除失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);

            else
            {
                if (ptr2.getLeft() == null && ptr2.getRight() == null) // 無子節點
                {
                    if (ptr1.getLeft() == ptr2) ptr1.setLeft(null);
                    else ptr1.setRight(null);
                }

                else if (ptr2.getLeft() != null && ptr2.getRight() != null) // 有兩個子節點
                {
                    node successor = ptr2.getRight();
                    node successorParent = ptr2;
                    while (successor.getLeft() != null)
                    {
                        successorParent = successor;
                        successor = successor.getLeft();
                    }
                    ptr2.setData(successor.getData());
                    if (successorParent.getLeft() == successor) successorParent.setLeft(successor.getRight());
                    else successorParent.setRight(successor.getRight());
                }
                else // 有一個子節點
                {
                    node child = (ptr2.getLeft() != null) ? ptr2.getLeft() : ptr2.getRight();
                    if (ptr1.getLeft() == ptr2) ptr1.setLeft(child);
                    else ptr1.setRight(child);
                }
            }

            inorder(root.getLeft());
            textBox1.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox2.Text = "";
            preorder(root.getLeft());
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox2.Text = "";
            inorder(root.getLeft());
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox2.Text = "";
            postorder(root.getLeft());
        }

        class node
        {
            int data;
            node left, right;

            public node(int n)
            {
                data = n;
                left = right = null;
            }

            public int getData()
            {
                return data;
            }

            public node getLeft()
            {
                return left;
            }

            public node getRight()
            {
                return right;
            }

            public void setData(int n)
            {
                data = n;
            }

            public void setLeft(node n)
            {
                left = n;
            }

            public void setRight(node n)
            {
                right = n;
            }
        }

        void inorder(node ptr)
        {
            if (ptr != null)
            {
                inorder(ptr.getLeft());
                textBox2.Text += ptr.getData() + " ";
                inorder(ptr.getRight());
            }
        }

        void preorder(node ptr)
        {
            if (ptr != null)
            {
                textBox2.Text += ptr.getData() + " ";
                preorder(ptr.getLeft());
                preorder(ptr.getRight());
            }
        }

        void postorder(node ptr)
        {
            if (ptr != null)
            {
                postorder(ptr.getLeft());
                postorder(ptr.getRight());
                textBox2.Text += ptr.getData() + " ";
            }
        }
    }
}
