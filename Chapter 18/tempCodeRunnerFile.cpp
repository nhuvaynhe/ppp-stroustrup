for (int index=1; index<11; ++index) {

        aa[index -1] = 1;

        for (int i=1; i<=index; ++i) {
            aa[index -1] *= i;
        }
    }