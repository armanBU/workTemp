clock_t start, end1;
start = clock();

end1 = clock();
double duration_sec = double(end1-start)/CLOCKS_PER_SEC;
cout<<duration_sec<<"\n";
