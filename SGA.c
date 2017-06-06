#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char FLAG = 0;
const unsigned short NPARAMS = 8;
const unsigned short NIND = 10;
const unsigned short NBITS[] = {3, 3, 3, 3, 3, 3, 3, 3};
const float P_MUTATION = 0.001;
const float CROSSPROB = 0.8;
#define LLIMIT 0
#define ULIMIT 8
double RANGE = ULIMIT - LLIMIT;
#define GLIMIT 10
#define ERROR 0.001
const unsigned short SAMPLE[] = { 5, 5, 5, 3, 5, 7, 0, 7};

#include "INDIVIDUAL-init.h"
#include "POPULATION-init.h"
#include "POPULATION-eval.h"
#include "SELECTION.h"
#include "CROSSING.h"
#include "MUTATION.h"

int main(int argc, char const *argv[]) {
  //srand(time(NULL));
  INDIVIDUAL * ppltn, * newPpltn, * bestInd;
  unsigned short nGeneration = 1, i, nCrossed;
  unsigned short ** Crosstable, * newInds;
  int x, y;

  newInds = (unsigned short *)malloc(NIND*sizeof(unsigned short));

  ppltn = allocPopulation();
  newPpltn = allocPopulation();
  if(ppltn == NULL || newPpltn == NULL) return 1;

  // Initialize Population
  if( initPopulation(ppltn) == 1 || initPopulation(newPpltn) == 1){
    printf("Cannot initialize individual properly\n");
    return 1;
  }

  // EvaluatePopulation returns a pointer to the better individual of the population
  bestInd = EvaluatePopulation(ppltn);
  //showPopulation(ppltn);
  showGeneration(ppltn);
  // Stop condition
  while(nGeneration < GLIMIT /*&& bestInd->fitness > ERROR*/) {

    printf("\n\tGeneration %u\n", nGeneration+1);
    Crosstable=rouletteSelection(ppltn, Crosstable);
    //printf("Cross table computed\n");
    nCrossed = crossPopulation(ppltn, newPpltn, Crosstable, newInds);
    //printf("Population crossed\n");
    MutatePopulation(ppltn, newInds, nCrossed);
    bestInd = EvaluatePopulation(ppltn);
    //showPopulation(ppltn);
    showGeneration(ppltn);
    nGeneration++;
  }
  printf("\nBest Individual, generation %u\n", nGeneration);
  //showGenes(bestInd);
  //showFitness(bestInd);
  printf("\t"); showIndividual(bestInd);

  //showPopulation(ppltn);

  return 0;
}
