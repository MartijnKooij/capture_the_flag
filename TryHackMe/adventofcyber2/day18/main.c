// CrackMe.MainForm
using System;
using System.ComponentModel;
using System.Drawing;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using CrackMe;

public class MainForm : Form
{
	private Label labelKey;

	private TextBox textBoxKey;

	private Panel panelLogo;

	private TableLayoutPanel tableLayoutPanel1;

	private Button buttonActivate;

	private TableLayoutPanel tableLayoutPanelButtons;

	private Label labelOrg;

	private Container components;

	public MainForm()
	{
		try
		{
			InitializeComponent();
		}
		catch
		{
			//try-fault
			base.Dispose(disposing: true);
			throw;
		}
	}

	private void ~MainForm()
	{
		((IDisposable)components)?.Dispose();
	}

	private void InitializeComponent()
	{
		System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CrackMe.MainForm));
		labelKey = new System.Windows.Forms.Label();
		textBoxKey = new System.Windows.Forms.TextBox();
		panelLogo = new System.Windows.Forms.Panel();
		tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
		buttonActivate = new System.Windows.Forms.Button();
		tableLayoutPanelButtons = new System.Windows.Forms.TableLayoutPanel();
		labelOrg = new System.Windows.Forms.Label();
		tableLayoutPanel1.SuspendLayout();
		tableLayoutPanelButtons.SuspendLayout();
		SuspendLayout();
		labelKey.Anchor = System.Windows.Forms.AnchorStyles.Right;
		labelKey.AutoSize = true;
		System.Drawing.Point location = new System.Drawing.Point(30, 14);
		labelKey.Location = location;
		labelKey.Name = "labelKey";
		System.Drawing.Size size = new System.Drawing.Size(56, 13);
		labelKey.Size = size;
		labelKey.TabIndex = 0;
		labelKey.Text = "Password:";
		labelKey.Click += new System.EventHandler(labelKey_Click);
		textBoxKey.Anchor = System.Windows.Forms.AnchorStyles.Left;
		System.Drawing.Point location2 = new System.Drawing.Point(92, 10);
		textBoxKey.Location = location2;
		textBoxKey.Name = "textBoxKey";
		System.Drawing.Size size2 = new System.Drawing.Size(160, 20);
		textBoxKey.Size = size2;
		textBoxKey.TabIndex = 1;
		textBoxKey.TextChanged += new System.EventHandler(textBoxKey_TextChanged);
		panelLogo.BackgroundImage = (System.Drawing.Image)resources.GetObject("panelLogo.BackgroundImage");
		panelLogo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
		panelLogo.Dock = System.Windows.Forms.DockStyle.Top;
		System.Drawing.Point location3 = new System.Drawing.Point(0, 0);
		panelLogo.Location = location3;
		panelLogo.Name = "panelLogo";
		System.Drawing.Size size3 = new System.Drawing.Size(299, 100);
		panelLogo.Size = size3;
		panelLogo.TabIndex = 2;
		panelLogo.Paint += new System.Windows.Forms.PaintEventHandler(panelLogo_Paint);
		tableLayoutPanel1.ColumnCount = 2;
		tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30f));
		tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 70f));
		tableLayoutPanel1.Controls.Add(labelKey, 0, 0);
		tableLayoutPanel1.Controls.Add(textBoxKey, 1, 0);
		tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Bottom;
		System.Drawing.Point location4 = new System.Drawing.Point(0, 137);
		tableLayoutPanel1.Location = location4;
		tableLayoutPanel1.Name = "tableLayoutPanel1";
		tableLayoutPanel1.RowCount = 1;
		tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100f));
		System.Drawing.Size size4 = new System.Drawing.Size(299, 41);
		tableLayoutPanel1.Size = size4;
		tableLayoutPanel1.TabIndex = 8;
		buttonActivate.Anchor = System.Windows.Forms.AnchorStyles.None;
		System.Drawing.Point location5 = new System.Drawing.Point(111, 11);
		buttonActivate.Location = location5;
		buttonActivate.Name = "buttonActivate";
		System.Drawing.Size size5 = new System.Drawing.Size(75, 23);
		buttonActivate.Size = size5;
		buttonActivate.TabIndex = 3;
		buttonActivate.Text = "Submit Password";
		buttonActivate.UseVisualStyleBackColor = true;
		buttonActivate.Click += new System.EventHandler(buttonActivate_Click);
		tableLayoutPanelButtons.ColumnCount = 3;
		tableLayoutPanelButtons.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333f));
		tableLayoutPanelButtons.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33334f));
		tableLayoutPanelButtons.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33334f));
		tableLayoutPanelButtons.Controls.Add(labelOrg, 0, 0);
		tableLayoutPanelButtons.Controls.Add(buttonActivate, 1, 0);
		tableLayoutPanelButtons.Dock = System.Windows.Forms.DockStyle.Bottom;
		System.Drawing.Point location6 = new System.Drawing.Point(0, 178);
		tableLayoutPanelButtons.Location = location6;
		tableLayoutPanelButtons.Name = "tableLayoutPanelButtons";
		tableLayoutPanelButtons.RowCount = 1;
		tableLayoutPanelButtons.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333f));
		System.Drawing.Size size6 = new System.Drawing.Size(299, 46);
		tableLayoutPanelButtons.Size = size6;
		tableLayoutPanelButtons.TabIndex = 7;
		labelOrg.Dock = System.Windows.Forms.DockStyle.Fill;
		System.Drawing.Color grayText = System.Drawing.SystemColors.GrayText;
		labelOrg.ForeColor = grayText;
		System.Drawing.Point location7 = new System.Drawing.Point(3, 0);
		labelOrg.Location = location7;
		labelOrg.Name = "labelOrg";
		System.Drawing.Size size7 = new System.Drawing.Size(93, 46);
		labelOrg.Size = size7;
		labelOrg.TabIndex = 4;
		labelOrg.Text = "The Best Festival Company 2020";
		labelOrg.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
		base.AcceptButton = buttonActivate;
		System.Drawing.SizeF sizeF2 = (base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f));
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		System.Drawing.Size size9 = (base.ClientSize = new System.Drawing.Size(299, 224));
		base.Controls.Add(tableLayoutPanel1);
		base.Controls.Add(tableLayoutPanelButtons);
		base.Controls.Add(panelLogo);
		base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
		base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
		base.MaximizeBox = false;
		base.MinimizeBox = false;
		base.Name = "MainForm";
		Text = "TBFC Dashboard";
		base.Load += new System.EventHandler(MainForm_Load);
		tableLayoutPanel1.ResumeLayout(false);
		tableLayoutPanel1.PerformLayout();
		tableLayoutPanelButtons.ResumeLayout(false);
		ResumeLayout(false);
	}

	private void MainForm_Load(object sender, EventArgs e)
	{
	}

	private void buttonExit_Click(object sender, EventArgs e)
	{
		Close();
	}

	private void buttonAbout_Click(object sender, EventArgs e)
	{
		new AboutForm().ShowDialog();
	}

	private unsafe void buttonActivate_Click(object sender, EventArgs e)
	{
		IntPtr value = Marshal.StringToHGlobalAnsi(textBoxKey.Text);
		sbyte* ptr = (sbyte*)System.Runtime.CompilerServices.Unsafe.AsPointer(ref <Module>.??_C@_0BB@IKKDFEPG@santapassword321@);
		void* ptr2 = (void*)value;
		byte b = *(byte*)ptr2;
		byte b2 = 115;
		if ((uint)b >= 115u)
		{
			while ((uint)b <= (uint)b2)
			{
				if (b != 0)
				{
					ptr2 = (byte*)ptr2 + 1;
					ptr++;
					b = *(byte*)ptr2;
					b2 = (byte)(*ptr);
					if ((uint)b < (uint)b2)
					{
						break;
					}
					continue;
				}
				MessageBox.Show("Welcome, Santa, here's your flag thm{046af}", "That's the right key!", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
				return;
			}
		}
		MessageBox.Show("Uh Oh! That's the wrong key", "You're not Santa!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}

	private void panelLogo_Paint(object sender, PaintEventArgs e)
	{
	}

	private void textBoxKey_TextChanged(object sender, EventArgs e)
	{
	}

	private void labelKey_Click(object sender, EventArgs e)
	{
	}

	[HandleProcessCorruptedStateExceptions]
	protected override void Dispose([MarshalAs(UnmanagedType.U1)] bool A_0)
	{
		if (A_0)
		{
			try
			{
				~MainForm();
			}
			finally
			{
				base.Dispose(disposing: true);
			}
		}
		else
		{
			base.Dispose(disposing: false);
		}
	}
}
