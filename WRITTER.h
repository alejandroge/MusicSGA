int Writter(INDIVIDUAL * MusicArray);

int Writter(INDIVIDUAL * MusicArray){
    FILE *Principal, *Secondary;
    char c;
    int i;
    Principal = fopen("Output.xml", "wt");

    Secondary=fopen("xml-temps/Top.txt","rt" );
    while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
        fputc(c,Principal);

	if(ferror(Secondary) || ferror(Secondary))
		return 1;

	fclose(Secondary);

  for (i=0;i<NPARAMS;i++){

      if(i==8){
          Secondary=fopen("xml-temps/Middle.txt","rt" );
          while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
              fputc(c,Principal);

          if(ferror(Secondary) || ferror(Secondary))
              return 1;

          fclose(Secondary);
      }

      switch(MusicArray->value[i]){
          case 1:
              Secondary=fopen("xml-temps/G3.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 2:
              Secondary=fopen("xml-temps/A3.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 3:
              Secondary=fopen("xml-temps/B3.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 4:
              Secondary=fopen("xml-temps/C4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 5:
              Secondary=fopen("xml-temps/D4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 6:
              Secondary=fopen("xml-temps/E4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 7:
              Secondary=fopen("xml-temps/F4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 8:
              Secondary=fopen("xml-temps/G4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 9:
              Secondary=fopen("xml-temps/A4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 10:
              Secondary=fopen("xml-temps/B4.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 11:
              Secondary=fopen("xml-temps/C5.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 12:
              Secondary=fopen("xml-temps/D5.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 13:
              Secondary=fopen("xml-temps/E5.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 14:
              Secondary=fopen("xml-temps/F5.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          case 15:
              Secondary=fopen("xml-temps/G5.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);
              break;

          default:
              Secondary=fopen("xml-temps/r.txt","rt" );
              while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
                  fputc(c,Principal);

              if(ferror(Secondary) || ferror(Secondary))
                  return 1;

              fclose(Secondary);


      }
    }

    Secondary=fopen("xml-temps/Bottom.txt","rt" );
    while((c=fgetc(Secondary))!=EOF && !ferror(Secondary) && !ferror(Principal))
        fputc(c,Principal);

	if(ferror(Secondary) || ferror(Secondary))
		return 1;

	fclose(Secondary);

    fclose(Principal);
}
