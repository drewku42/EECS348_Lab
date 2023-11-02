/*
Drew Meyer
3020061
Lab 5
Given 12 monthly sales numbers, return sales reports.
*/

#include <stdio.h>
#include <string.h>

void display_monthly_sales(float sales[], char months[][10]) {
   printf("\nMonthly Sales report for 2022: \n");
   printf("Month -> Sales\n");
   for (int i = 0; i < 12; i++) {
      printf("%s -> $%.2f\n", months[i], sales[i]);
   }
}

float calculate_average(float sales[]) {
   float average = 0;
   for (int i = 0; i < 12; i++) {
      average += sales[i];
   }
   return average / 12;
}

void find_min_max(float sales[], char months[][10], float *min, float *max, char **min_month, char **max_month) {
   *min = sales[0];
   *min_month = months[0];
   *max = sales[0];
   *max_month = months[0];

   for (int i = 1; i < 12; i++) {
      if (sales[i] > *max) {
         *max = sales[i];
         *max_month = months[i];
      }
      if (sales[i] < *min) {
         *min = sales[i];
         *min_month = months[i];
      }
   }
}

void six_month_avg(float sales[], char months[][10]) {
   for (int i = 0; i < 7; i++) {
      float sum = 0;
      for (int j = i; j < i + 6; j++) {
         sum += sales[j];
      }
      float avg = sum / 6;
      printf("%s - %s $%.2f\n", months[i], months[i + 5], avg);
   }
}

void sort_and_display(float sales[], char months[][10]) {
   for (int i = 0; i < 12; i++) {
      for (int j = i + 1; j < 12; j++) {
         if (sales[j] > sales[i]) {
            float tmp = sales[i];
            sales[i] = sales[j];
            sales[j] = tmp;

            char tmp_month[9];
            strncpy(tmp_month, months[i], 9);
            strncpy(months[i], months[j], 9);
            strncpy(months[j], tmp_month, 9);
         }
      }
   }
   printf("Month -> Sales\n");
   for (int i = 0; i < 12; i++) {
      printf("%s -> $%.2f\n", months[i], sales[i]);
   }
}

int main() {
   char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

   display_monthly_sales(sales, months);
   float average = calculate_average(sales);
   printf("\nSales summary: \n");
   printf("Average sales: $%.2f\n", average);

   float min, max;
   char *min_month, *max_month;
   find_min_max(sales, months, &min, &max, &min_month, &max_month);
   printf("Minimum sales: $%.2f   (%s)\n", min, min_month);
   printf("Maximum sales: $%.2f   (%s)\n", max, max_month);


   printf("\nSix-Month Moving Average Report:\n");
   six_month_avg(sales, months);

   printf("\nSales Report (Highest to Lowest)\n");
   sort_and_display(sales, months);

   return 0;
}

