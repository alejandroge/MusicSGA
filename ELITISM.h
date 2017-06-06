void Elitism(INDIVIDUAL bestInd, INDIVIDUAL * ppltn);

void Elitism(INDIVIDUAL bestInd, INDIVIDUAL * ppltn) {
  unsigned short i, worstInd;
  double currentFitness;

  // Looks for the position of the worst individual in the population, or at
  // least worse than the best
  currentFitness = bestInd.fitness;
  worstInd = 0;
  for(i=0; i<NIND; i++) {
    //printf("%g -- %g\n", ppltn[i].fitness, currentFitness);
    if(ppltn[i].fitness < currentFitness) {
      worstInd = i;
      currentFitness = ppltn[i].fitness;
    }
  } //printf("Worst Ind found: %u\n", worstInd+1);

  // The best ind takes the place of the worst in the next generation
  for(i=0; i<ppltn[0].ncbits; i++) {
    ppltn[worstInd].chromosome[i] = bestInd.chromosome[i];
  }
}
