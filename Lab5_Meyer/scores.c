#include <stdio.h>

void findCombinations(int score, int td2pt, int tdFg, int td, int fg, int safety) {
   if (score == 0) {
      printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFg, td, fg, safety);
      return;
   }
   
   if (score < 0) {
      return;
   }
   
   findCombinations(score - 8, td2pt + 1, tdFg, td, fg, safety);
   findCombinations(score - 7, td2pt, tdFg + 1, td, fg, safety);
   findCombinations(score - 6, td2pt, tdFg, td + 1, fg, safety);
   findCombinations(score - 3, td2pt, tdFg, td, fg + 1, safety);
   findCombinations(score - 2, td2pt, tdFg, td, fg, safety + 1);
}

int main() {
   int score;
   
   do {
      printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
      scanf("%d", &score);
      
      if (score <= 1) {
         break;
      }
      
      printf("Possible combinations of scoring plays:\n");
      findCombinations(score, 0, 0, 0, 0, 0);
   } while (1);
   
   return 0;
}

