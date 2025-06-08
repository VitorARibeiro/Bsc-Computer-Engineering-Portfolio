using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ip_Converter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int ip1 = int.Parse(textBox1.Text);
            int ip2 = int.Parse(textBox2.Text);
            int ip3 = int.Parse(textBox3.Text);
            int ip4 = int.Parse(textBox4.Text);

            int[] Bin1 = new int[8];
            int[] Bin2 = new int[8];
            int[] Bin3 = new int[8];
            int[] Bin4 = new int[8];

            //converter ip1 

            for (int i = 7; i >= 0; i--)
            {
                Bin1[i] = ip1 % 2;
                ip1 = ip1 / 2;

                Bin2[i] = ip2 % 2;
                ip2 = ip2 / 2;

                Bin3[i] = ip3 % 2;
                ip3 = ip3 / 2;

                Bin4[i] = ip4 % 2;
                ip4 = ip4 / 2;
            }

            // Convert binary arrays to strings and concatenate
            string binaryIP = string.Join("", Bin1) + "." + string.Join("", Bin2) + "." + string.Join("", Bin3) + "." + string.Join("", Bin4);

            labelResult.Text = binaryIP;



        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void ipParaBinarioToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }
    }
}
