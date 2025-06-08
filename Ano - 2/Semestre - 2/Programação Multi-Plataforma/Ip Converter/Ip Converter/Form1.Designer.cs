namespace Ip_Converter
{
    partial class Form1
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.labelResult = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.ipParaBinarioToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.binarioParaIpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.ipParaBinarioToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.binarioParaIpToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.ipParaBinarioToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(100, 127);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 31);
            this.textBox1.TabIndex = 0;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(266, 127);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 31);
            this.textBox2.TabIndex = 1;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(434, 127);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 31);
            this.textBox3.TabIndex = 2;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(596, 127);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 31);
            this.textBox4.TabIndex = 3;
            // 
            // labelResult
            // 
            this.labelResult.AutoSize = true;
            this.labelResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.labelResult.Location = new System.Drawing.Point(52, 242);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(655, 39);
            this.labelResult.TabIndex = 4;
            this.labelResult.Text = "00000000.00000000.00000000.00000000";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(293, 319);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(188, 78);
            this.button1.TabIndex = 5;
            this.button1.Text = "Converter";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ipParaBinarioToolStripMenuItem,
            this.binarioParaIpToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(243, 80);
            // 
            // ipParaBinarioToolStripMenuItem
            // 
            this.ipParaBinarioToolStripMenuItem.Name = "ipParaBinarioToolStripMenuItem";
            this.ipParaBinarioToolStripMenuItem.Size = new System.Drawing.Size(300, 38);
            this.ipParaBinarioToolStripMenuItem.Text = "Ip para Binario";
            // 
            // binarioParaIpToolStripMenuItem
            // 
            this.binarioParaIpToolStripMenuItem.Name = "binarioParaIpToolStripMenuItem";
            this.binarioParaIpToolStripMenuItem.Size = new System.Drawing.Size(300, 38);
            this.binarioParaIpToolStripMenuItem.Text = "Binario para Ip";
            // 
            // menuStrip1
            // 
            this.menuStrip1.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ipParaBinarioToolStripMenuItem1});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(785, 42);
            this.menuStrip1.TabIndex = 7;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // ipParaBinarioToolStripMenuItem1
            // 
            this.ipParaBinarioToolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.binarioParaIpToolStripMenuItem1,
            this.ipParaBinarioToolStripMenuItem2});
            this.ipParaBinarioToolStripMenuItem1.Name = "ipParaBinarioToolStripMenuItem1";
            this.ipParaBinarioToolStripMenuItem1.Size = new System.Drawing.Size(97, 38);
            this.ipParaBinarioToolStripMenuItem1.Text = "Menu";
            this.ipParaBinarioToolStripMenuItem1.Click += new System.EventHandler(this.ipParaBinarioToolStripMenuItem1_Click);
            // 
            // binarioParaIpToolStripMenuItem1
            // 
            this.binarioParaIpToolStripMenuItem1.Name = "binarioParaIpToolStripMenuItem1";
            this.binarioParaIpToolStripMenuItem1.Size = new System.Drawing.Size(359, 44);
            this.binarioParaIpToolStripMenuItem1.Text = "Binario para Ip";
            // 
            // ipParaBinarioToolStripMenuItem2
            // 
            this.ipParaBinarioToolStripMenuItem2.Name = "ipParaBinarioToolStripMenuItem2";
            this.ipParaBinarioToolStripMenuItem2.Size = new System.Drawing.Size(359, 44);
            this.ipParaBinarioToolStripMenuItem2.Text = "Ip para Binario";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 450);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.labelResult);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.contextMenuStrip1.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label labelResult;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem ipParaBinarioToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem binarioParaIpToolStripMenuItem;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem ipParaBinarioToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem binarioParaIpToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem ipParaBinarioToolStripMenuItem2;
    }
}

