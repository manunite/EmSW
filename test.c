#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

void hello (void)
{
  g_print ("Hello World\n");
}

void destroy (void)
{
  gtk_main_quit ();
}

struct R_Voca
{
	char Voca[100];
	char Mean[100];
};

int main (int argc, char *argv[])
{
  char R_voca[100];
  char R_mean[100];
  memset(R_voca,0x00,sizeof(R_voca));
  memset(R_mean,0x00,sizeof(R_mean));

  struct R_Voca getResult = R_Voca;
  getResult = Voca_Mean();

  strncpy(R_voca,getResult.Voca,strlen(getResult.Voca));
  strncpy(R_mean,getResult.Mean,strlen(getResult.Mean));

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_1,*button_2,*button_3,*button_4;
  GtkWidget *vbox_1, *vbox_2,*vbox_3,*vbox_4,*vbox_5;
  GtkWidget *hbox_1,*hbox_2;
  GtkWidget *label_Name, *label_Diff;
  GtkWidget *input_Name, *input_Diff;
  GtkWidget *QuizIntro, *Quiz;
  GtkWidget *result;
  GtkWidget *Title;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (destroy), NULL);
  //gtk_container_border_width (GTK_CONTAINER (window), 10);
  vbox_1 = gtk_vbox_new(TRUE,0);
  vbox_2 = gtk_vbox_new(TRUE,0);
  vbox_3 = gtk_vbox_new(TRUE,0);
  vbox_4 = gtk_vbox_new(TRUE,0);
  vbox_5 = gtk_vbox_new(TRUE,0);
  hbox_1 = gtk_hbox_new(TRUE,0);
  hbox_2 = gtk_hbox_new(TRUE,0);

  label_Name = gtk_label_new("Name");
  label_Diff = gtk_label_new("Difficulty");
  input_Name = gtk_label_new(R_voca);
  input_Diff = gtk_label_new(R_mean);
  QuizIntro = gtk_label_new("다음 단어의 뜻을 고르시오.");
  Quiz = gtk_label_new("단어가 나타나는 곳");
  Title = gtk_label_new("문제풀이");
  result = gtk_label_new("결과가 떠야함");

  button_1 = gtk_button_new_with_label ("1번");
  button_2 = gtk_button_new_with_label ("2번");
  button_3 = gtk_button_new_with_label ("3번");
  button_4 = gtk_button_new_with_label ("4번");

  gtk_widget_set_size_request(label_Name,200,60);
  gtk_widget_set_size_request(label_Diff,200,60);
  gtk_widget_set_size_request(input_Name,200,60);
  gtk_widget_set_size_request(input_Diff,200,60);
  gtk_widget_set_size_request(Title,100,60);
  gtk_widget_set_size_request(QuizIntro,100,60);
  gtk_widget_set_size_request(Quiz,100,60);
  gtk_widget_set_size_request(button_1,80,50);
  gtk_widget_set_size_request(button_2,80,50);
  gtk_widget_set_size_request(button_3,80,50);
  gtk_widget_set_size_request(button_4,80,50);
  gtk_widget_set_size_request(result,80,50);



  gtk_container_add(GTK_CONTAINER(vbox_1),label_Name);
  gtk_container_add(GTK_CONTAINER(vbox_1),label_Diff);
  gtk_container_add(GTK_CONTAINER(vbox_2),input_Name);
  gtk_container_add(GTK_CONTAINER(vbox_2),input_Diff);
  gtk_container_add(GTK_CONTAINER(vbox_3),Title);
  gtk_container_add(GTK_CONTAINER(vbox_4),QuizIntro);
  gtk_container_add(GTK_CONTAINER(vbox_4),Quiz);
  gtk_container_add(GTK_CONTAINER(vbox_5),result);
  gtk_container_add(GTK_CONTAINER(hbox_2),button_1);
  gtk_container_add(GTK_CONTAINER(hbox_2),button_2);
  gtk_container_add(GTK_CONTAINER(hbox_2),button_3);
  gtk_container_add(GTK_CONTAINER(hbox_2),button_4);
  
  

  //button = gtk_button_new_with_label ("Hello World");

  //gtk_signal_connect (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (hello), NULL);
  //gtk_signal_connect_object (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy), GTK_OBJECT (window));
  //gtk_container_add (GTK_CONTAINER (window), button);
  gtk_container_add (GTK_CONTAINER (hbox_1), vbox_1);
  gtk_container_add (GTK_CONTAINER (hbox_1), vbox_2);
  gtk_container_add (GTK_CONTAINER (vbox_3), hbox_1);
  gtk_container_add (GTK_CONTAINER (vbox_3), vbox_4);
  gtk_container_add (GTK_CONTAINER (vbox_3), hbox_2);
  gtk_container_add (GTK_CONTAINER (vbox_3), vbox_5);
  gtk_container_add (GTK_CONTAINER (window), vbox_3);
  gtk_widget_set_usize(window, 400, 300);
  //gtk_widget_show (button);
  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}
