namespace SdZSerialArduino
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.comboPort = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.comboVitesse = new System.Windows.Forms.ComboBox();
            this.btnConnexion = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.boxEmission = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.boxReception = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Port : ";
            // 
            // comboPort
            // 
            this.comboPort.FormattingEnabled = true;
            this.comboPort.Location = new System.Drawing.Point(55, 13);
            this.comboPort.Name = "comboPort";
            this.comboPort.Size = new System.Drawing.Size(121, 21);
            this.comboPort.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(183, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Vitesse : ";
            // 
            // comboVitesse
            // 
            this.comboVitesse.FormattingEnabled = true;
            this.comboVitesse.Location = new System.Drawing.Point(240, 13);
            this.comboVitesse.Name = "comboVitesse";
            this.comboVitesse.Size = new System.Drawing.Size(121, 21);
            this.comboVitesse.TabIndex = 3;
            // 
            // btnConnexion
            // 
            this.btnConnexion.Location = new System.Drawing.Point(367, 12);
            this.btnConnexion.Name = "btnConnexion";
            this.btnConnexion.Size = new System.Drawing.Size(87, 23);
            this.btnConnexion.TabIndex = 4;
            this.btnConnexion.Text = "Connecter";
            this.btnConnexion.UseVisualStyleBackColor = true;
            this.btnConnexion.Click += new System.EventHandler(this.btnConnexion_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Emission";
            // 
            // boxEmission
            // 
            this.boxEmission.AcceptsReturn = true;
            this.boxEmission.Location = new System.Drawing.Point(16, 62);
            this.boxEmission.Multiline = true;
            this.boxEmission.Name = "boxEmission";
            this.boxEmission.Size = new System.Drawing.Size(438, 101);
            this.boxEmission.TabIndex = 6;
            this.boxEmission.TextChanged += new System.EventHandler(this.boxEmission_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 170);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(56, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Réception";
            // 
            // boxReception
            // 
            this.boxReception.AcceptsReturn = true;
            this.boxReception.Location = new System.Drawing.Point(16, 186);
            this.boxReception.Multiline = true;
            this.boxReception.Name = "boxReception";
            this.boxReception.ReadOnly = true;
            this.boxReception.Size = new System.Drawing.Size(438, 101);
            this.boxReception.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(476, 311);
            this.Controls.Add(this.boxReception);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.boxEmission);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnConnexion);
            this.Controls.Add(this.comboVitesse);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comboPort);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "SdZ terminal voie série";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboPort;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboVitesse;
        private System.Windows.Forms.Button btnConnexion;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox boxEmission;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox boxReception;
    }
}

