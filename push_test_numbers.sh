#!/bin/sh
echo "make all"
make all
echo "must not recompile"
make all
echo "push_swap Check Duplicate, must display Error \ n"

./push_swap 1 1
./push_swap 12 12
./push_swap -1 -1
./push_swap 2147483647 2147483647
./push_swap -2147483648 -2147483648
./push_swap 3 1 3
./push_swap -1 2 3 4 -1
./push_swap 1 23 3 7 5 2 3 5 4 87 9 87 25 6 298 -7 963 2323 47 45 12 12 -7 54 6 34

echo "push_swap Wrongs values"

./push_swap -1-1
./push_swap a
./push_swap 1a
./push_swap 1 2 z 3
./push_swap 1 2 3z 4
./push_swap +1
./push_swap --1
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1 2 3 -7-8 4
./push_swap "1 \2"
./push_swap 214l
./push_swap @1 2

echo "Should display nothing"
./push_swap
./push_swap 42
./push_swap 1
./push_swap 1 2
./push_swap 1 2 3
./push_swap -1 0 1
./push_swap 0 1
./push_swap -2 -1 1 2 3

echo "https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php"

echo "2, 3 or less"
./push_swap 2 1 0
./push_swap 2 1 0 | wc -l
./push_swap 50 7 1
./push_swap 50 -7 1 | wc -l
./push_swap 2147483647 1 2

echo "12 or less"
./push_swap 2 1 5 4 6 | wc -l
./push_swap -3 4 -2 0 -1 | wc -l
./push_swap -21  46  -44  34  -14 | wc -l
./push_swap 5  34  -5  8  39 | wc -l
./push_swap 2147483647 34 -5 8 -2147483648 | wc -l
./push_swap -421 -347 -17 -187 -84 | wc -l
./push_swap -151 -314 -401 -43 -319 | wc -l
./push_swap -108  82  786  992  661 | wc -l

echo ">=1500 fail"
./push_swap -388  -256  -11  -437  -310  -210  -181  -209  -113  -102  -2  -88  -222  -484  -258  -290  -43  -410  -319  -162  -233  -467  -30  -40  -281  -237  -130  -419  -259  -387  -370  -53  -360  -277  -456  -406  -161  -87  -338  -46  -325  -213  -372  -391  -135  -358  -49  -107  -255  -129  -51  -50  -82  -273  -318  -196  -164  -182  -344  -248  -475  -72  -205  -335  -352  -433  -33  -498  -468  -177  -163  -253  -126  -289  -390  -303  -294  -254  -354  -462  -157  -327  -16  -321  -105  -443  -236  -94  -304  -296  -458  -307  -351  -12  -297  -439  -426  -139  -472  -311 | wc -l
./push_swap 234  44  204  196  228  32  67  416  432  453  350  214  420  323  232  246  304  220  286  427  95  452  89  102  129  481  404  94  78  243  3  66  376  121  108  448  291  240  229  73  236  135  177  208  251  428  268  409  226  378  292  262  257  472  375  358  330  99  302  396  422  49  130  261  15  172  461  250  394  186  34  425  216  150  469  426  48  80  492  351  170  128  442  45  360  36  359  255  209  300  219  345  266  274  200  167  70  28  371  134 | wc -l
./push_swap -111  380  259  -460  -384  59  -8  257  -50  -434  -400  -219  -296  -453  -443  -466  190  215  -52  -65  175  -38  16  47  -90  -408  211  -102  300  -4  -172  354  1  -179  458  -486  475  95  -51  -489  163  325  412  -449  52  -496  492  107  464  -447  251  344  224  -330  -122  463  106  -353  38  291  -235  -3  -288  -183  459  126  -497  -94  -320  417  250  58  -355  452  179  328  -299  -85  -495  -54  -35  -294  -53  382  96  318  -110  -180  -358  7  274  -159  87  336  -148  -32  -69  221  -266  448 | wc -l
./push_swap -418  -441  -363  -305  261  -238  290  -249  170  -303  -190  284  -241  -442  375  -151  -334  131  334  -408  253  258  133  370  -465  -272  228  41  452  357  16  -183  -430  -351  -406  408  -340  109  136  -79  -225  -355  -98  101  120  85  483  -482  219  -440  -350  422  412  314  172  -206  -389  -479  177  440  -219  233  -438  -294  106  -172  -187  76  -414  288  114  -252  -439  409  57  -7  353  -188  -386  338  -165  468  -87  -326  -102  -213  -202  -162  137  -67  -383  181  43  179  -471  -488  206  -159  352  -253 | wc -l
./push_swap 90  499  440  -71  -115  23  -472  80  -323  -400  -464  -114  -440  -101  65  421  453  -77  458  -98  -76  -304  74  422  -421  -142  -194  413  -186  -131  -384  167  -222  -173  -26  60  138  -290  -34  477  29  -230  -176  223  -56  -168  -228  -305  -382  -491  102  107  403  242  -193  152  418  354  333  331  -35  187  -105  76  -474  435  407  -155  75  -226  447  -395  -4  -438  -404  345  1  206  -422  298  -247  73  -137  -154  -402  -298  275  248  -479  -475  462  117  -343  174  -442  31  258  47  -457  -387 | wc -l
./push_swap -458  -53  -497  -100  292  243  -287  -208  -203  -251  -312  -421  -467  275  344  -149  -123  -155  -32  -487  -28  -366  124  4  -441  442  -494  -93  375  -17  35  406  -495  74  459  -128  -330  328  -297  10  -46  278  -106  -130  -218  -193  -425  -66  -201  -162  251  135  261  177  420  -196  270  416  -472  -347  324  -372  399  -244  170  359  266  -427  296  -351  50  -337  350  229  -329  -127  199  -13  408  -90  60  -275  131  340  -43  -402  85  34  -496  23  488  472  8  160  -173  -349  224  361  356  -190 | wc -l
./push_swap 66  255  199  284  272  334  86  -300  390  -39  35  145  84  92  5  -323  403  203  196  76  169  198  -252  414  -1  -308  -73  10  -95  183  -89  -160  322  305  -259  453  -119  -80  6  -359  38  -43  147  185  -118  -112  -57  -103  123  -352  205  269  -131  465  -325  -330  216  -29  402  -301  217  -304  14  -498  151  16  455  234  298  62  -449  -422  -188  81  -329  479  172  451  -218  488  165  -342  -216  424  140  -147  -199  -182  340  251  22  339  -429  317  -286  -155  309  328  290  -10 | wc -l
./push_swap 38  19  -36  -4  -5  47  14  25  -38  36  -29  6  -3  -16  39  -48  5  -22  33  -17  35  26  -31  7  10  48  -11  -15  -12  37  45  -18  -10  32  -13  28  31  41  24  1  50  18  -9  4  -39  30  -41  -14  2  -26  -35  34  20  11  0  3  17  -28  -46  -24  -25  -21  -43  -2  44  15  9  40  -7  27  -20  -27  13  21  -6  -23  -49  23  8  -30  -47  43  29  -37  -33  46  -8  -32  -45  -40  12  22  -42  -19  16  -34  -1  49  42  -44 | wc -l
./push_swap 31  -28  45  -36  -21  -19  37  47  34  -43  15  -31  50  -12  -40  39  -24  -8  -20  22  -41  20  -46  3  26  -44  29  -1  9  -15  5  -30  -37  16  12  10  -14  -22  40  18  30  -47  36  -33  -42  17  23  43  24  48  -45  32  1  -25  44  25  -23  21  -16  7  -2  49  8  -10  -34  38  -29  2  -38  0  46  27  -9  -26  11  14  19  -27  -17  13  -4  35  -39  -3  4  -35  -18  -11  -32  33  -5  -6  -13  6  -48  -49  42  -7  28  41 | wc -l
./push_swap -43  16  -36  -7  -5  -20  18  -11  27  12  6  45  -31  21  23  -30  14  25  41  -15  -35  49  -47  -19  -22  -1  -39  -41  36  50  -48  5  32  -42  -33  38  -12  -28  -9  9  -25  10  37  28  -4  4  -6  22  -32  3  -14  19  -46  42  24  11  -3  8  -29  47  -34  -37  35  -44  -21  -2  29  17  39  -18  26  -27  -49  31  13  48  33  20  -40  -23  7  -26  43  46  -13  2  -16  0  40  -38  34  44  -24  1  -17  -10  -45  30  15  -8 | wc -l
./push_swap -36  28  8  41  12  43  -24  -48  26  32  -21  -41  7  0  27  20  -2  -27  -43  31  -1  4  47  -19  10  -4  -17  3  -14  -34  -26  46  -49  -5  11  48  39  22  44  -15  -32  1  -47  -11  34  33  -16  -37  -40  23  -38  -29  -3  14  5  -45  -9  -22  -20  21  -18  6  -10  9  -33  49  50  16  2  25  19  42  18  17  -31  29  -39  -7  -28  36  -25  37  -8  13  -30  -42  24  15  -6  -44  40  35  -46  -23  -35  -12  45  38  -13  30 | wc -l

echo ">= 11500"
./push_swap -182  -58  -68  -161  -42  -191  198  -111  153  96  159  -49  107  101  -155  9  -190  -154  210  109  249  -175  -132  -115  -9  129  -57  78  -224  48  131  -169  -74  -76  226  -32  97  -66  -56  26  88  108  204  64  253  -36  91  -244  180  20  -172  -18  5  157  -258  25  -105  209  -28  -11  -2  43  -205  -247  -37  -149  251  29  134  -225  72  -4  158  -78  -106  236  -145  31  -43  11  -231  68  -239  -92  -148  -103  -223  -170  -187  127  117  37  146  -213  111  123  118  61  59  -113  119  -147  229  87  152  230  32  178  -259  -98  -130  -142  -52  -193  -51  -212  41  161  246  220  -228  155  -59  -23  150  -146  160  125  139  -120  15  -208  -252  -240  185  -167  -166  -108  168  -75  120  -229  -6  85  217  13  21  74  84  104  -255  -26  36  -158  215  142  92  231  234  -88  63  227  -141  216  -45  224  44  -238  199  -186  -249  71  238  243  -129  140  -87  -34  171  49  116  -44  -101  254  189  -119  -80  188  62  212  -95  -136  -171  -218  190  -248  17  -67  151  82  -35  233  -125  -91  194  -47  -46  -144  176  -135  -81  -12  122  -232  -195  -207  22  213  221  -183  -152  -63  12  -202  -13  100  34  -206  -260  70  103  232  143  -38  -173  183  -93  136  -162  -31  60  223  102  55  -126  -90  -107  -24  -160  -19  -150  16  -54  14  -70  -61  -16  -116  -256  -214  -41  -181  162  -25  23  -143  3  28  -211  259  135  -127  24  -203  156  163  197  -204  -200  -236  -122  10  66  154  -39  -241  -177  -227  -15  -201  -109  95  -157  192  -234  -62  -250  112  79  75  39  -89  -245  242  -199  -10  -139  -84  241  169  -128  -197  133  -235  -174  -64  -17  113  -219  -104  -131  46  222  -8  -112  202  196  245  181  -230  166  -124  -53  -253  1  -216  -123  58  195  137  -102  -220  -83  201  170  205  182  -55  239  -194  -48  56  -188  207  -22  -251  -50  145  -222  -29  106  -254  94  40  -65  240  57  149  -20  132  148  53  30  93  89  -33  38  -60  -27  86  167  244  218  257  -168  -14  19  124  -242  172  121  -217  -118  258  47  214  8  -3  -1  51  165  -243  187  -226  83  27  175  -237  -233  228  -85  110  -180  4  -121  130  -97  -69  6  -114  237  128  174  141  -198  76  -138  54  147  126  69  35  77  -257  114  -176  219  -163  18  173  -71  99  -100  193  -140  184  -215  -153  -72  -77  2  260  -185  -79  -30  105  65  98  203  -192  -178  256  -210  81  -73  -196  164  138  -40  -96  -184  45  200  191  -151  80  115  -164  -137  -156  235  42  -117  -189  250  67  247  206  -221  208  -134  252  -209  -179  -133  -246  90  -159  -165  -7 | wc -l
./push_swap -70  -28  -63  205  207  -81  30  87  -163  -10  -120  216  -43  125  -112  -62  -47  -245  210  -123  -260  -243  67  -221  62  190  57  234  -79  -113  218  199  181  -57  129  -45  -102  131  -257  -217  213  209  223  54  157  121  -201  79  -106  -54  -153  84  5  243  19  244  176  -228  -104  -86  -219  204  180  39  32  165  -138  -33  -251  -151  -46  188  111  42  -208  122  15  17  -252  48  -235  231  -249  43  -175  193  -130  -139  -56  152  220  -21  -13  171  -142  161  -198  -179  162  80  33  100  60  114  172  29  254  -210  -80  -246  143  -71  -107  137  -23  -162  -30  -114  -191  -173  -1  -108  178  93  -44  27  12  81  -126  -187  -40  86  51  -82  -140  -178  -58  65  94  159  45  -200  -164  74  -99  -95  -97  239  104  -88  91  -244  -146  -41  -90  -220  83  105  154  -27  167  89  -236  -109  -147  -157  13  169  -211  -50  -148  229  -154  64  -229  228  -131  195  -11  10  242  6  41  7  -189  116  255  115  36  69  112  245  -259  -152  -159  38  -103  134  150  -233  -172  201  -73  -224  -100  -96  -240  46  -122  -49  113  72  9  -32  -234  -184  202  -12  -83  35  1  -101  155  149  -205  -218  120  -64  85  212  -135  247  76  -76  -67  260  -19  192  -117  -197  -78  182  144  22  56  258  153  175  20  -177  -238  214  40  -247  -230  -223  -85  -134  -132  108  135  160  -6  179  191  219  233  -69  222  -84  -143  11  -59  34  -105  71  217  187  -65  49  -226  -186  -7  -180  53  -169  47  -199  139  200  68  21  232  -66  -174  2  26  -203  198  -241  248  252  249  -254  -144  -171  -91  -225  8  -215  246  -155  14  -61  250  126  119  -24  142  -255  197  -202  -4  70  -121  -16  98  -22  -237  73  -227  164  123  103  78  -216  -55  238  -5  -15  55  -195  37  141  66  -98  -209  -193  -150  -242  -141  127  253  28  -167  -20  95  230  -35  -181  -72  -256  -116  -77  -207  -36  -31  -170  -119  63  140  -182  18  194  -14  185  3  -92  -17  -258  -239  -93  -38  -214  133  257  -166  241  117  -39  235  58  -87  118  -136  -161  166  -9  109  145  225  -176  -156  -213  183  146  251  -74  16  215  -253  90  77  -160  -127  -190  -248  189  130  128  -231  226  148  97  -29  124  -110  256  136  236  61  184  75  -89  25  206  151  -168  173  170  -37  -68  203  -165  -34  107  -52  106  -53  -206  -42  186  -232  -18  237  -204  -125  211  259  -137  -26  -60  99  -128  -3  23  -2  24  227  -115  -222  102  -94  177  96  147  163  -75  -129  168  -185  -158  240  0  138  92  132  44  -212  52  -192  -145  208  174  31  -118  101  -188  224  82 | wc -l

./push_swap -219  168  -39  -10  -103  -4  205  180  140  157  -41  -201  -240  192  -160  109  12  -141  182  91  185  -150  99  122  -47  118  -204  86  158  -214  234  204  150  121  93  258  -187  -191  43  -170  -237  97  -61  128  54  -260  161  -145  -208  9  213  178  59  117  -223  -178  112  240  253  -227  76  64  -180  169  249  -74  92  203  -104  -79  -212  -93  -94  173  -28  48  123  -51  -258  224  259  29  5  -24  -205  212  -37  67  60  145  -184  -232  -156  226  -182  -172  41  -135  -96  246  -246  -1  -117  164  170  53  148  -175  -239  254  172  -3  183  90  -236  -101  -13  -216  -21  218  -66  -15  -254  -194  174  171  -256  -195  119  6  -222  199  -84  -163  136  -199  -42  -58  84  -215  -65  20  236  -63  11  -154  242  -234  141  191  89  -128  -23  217  33  219  -40  -255  -115  -95  -99  31  -36  37  243  -20  -200  -193  -82  -52  -27  102  -241  198  216  220  51  -169  -22  184  221  -218  -138  -203  83  -120  -97  -57  -50  -211  -174  77  -2  30  38  -35  -131  -144  -127  166  13  -81  -83  -229  -6  247  15  -197  47  98  22  71  -250  -207  138  237  -189  88  62  74  -158  235  -198  181  100  101  -231  -217  120  147  105  194  -159  196  -257  -259  -30  195  14  -85  -62  108  229  188  146  -224  -165  -33  155  -122  -164  -226  -12  -107  -233  66  -54  241  -185  -186  -98  26  28  -71  72  -102  -48  130  -132  233  223  -106  -210  104  -245  -155  82  106  222  -88  -161  25  175  250  -87  -206  -8  7  -173  -253  -121  132  -142  -124  -105  -68  -225  -116  244  -168  4  18  107  186  -75  190  -171  34  156  23  42  -110  75  -139  167  50  144  -137  -130  207  96  256  -248  -18  206  -16  163  32  215  129  -69  95  -100  -5  -146  251  -220  -91  -14  -67  -111  197  228  -76  127  94  -78  231  -244  -45  -70  -162  -89  230  68  44  -147  238  -92  239  36  81  63  -29  -72  103  -11  193  -46  151  -136  179  65  -235  110  -140  -125  126  -31  -32  252  -181  -38  142  114  211  -109  -7  57  -209  -247  45  0  73  113  133  10  -55  149  257  139  177  255  -19  153  70  115  -249  -167  -196  131  -17  -73  -238  -60  -118  202  16  134  -179  137  52  -177  61  -230  -86  -44  -192  -213  40  135  176  -113  -126  225  21  2  -80  -34  55  -129  227  111  -119  245  -228  -190  69  -108  -77  260  -43  58  -112  -243  248  124  116  -202  201  -166  -188  -59  -49  200  214  -252  -90  -9  -151  -143  27  -123  8  87  125  49  -134  210  -133  -153  -114  -157  -183  160  3  187  35  -242  56  152  209  -148  154  232  -25  -149  79  -53  -56 | wc -l

./push_swap 150  -76  63  53  67  -86  -181  -219  119  224  57  179  -139  78  -158  -117  -119  176  -3  -228  -120  214  187  79  17  11  167  -62  234  225  -240  175  213  47  85  69  221  -180  -138  -51  247  -45  -89  -81  95  -105  -130  -103  -152  222  168  112  -223  236  -16  -194  10  58  -176  -21  -214  171  198  173  -232  217  -217  -48  -95  159  129  92  239  -121  -55  0  155  162  211  60  -41  72  -78  243  -31  -185  190  -79  48  -155  7  192  -129  126  -164  -118  -212  186  -153  -196  -236  231  -151  -73  128  135  118  174  115  -175  245  -32  163  -177  124  202  142  151  59  -210  -124  181  -231  -191  -178  84  -154  -65  -238  205  -237  -87  -229  -7  -197  -192  -146  -58  -88  -225  -64  -90  242  -35  -4  -143  -24  -198  -193  93  -13  -184  144  -111  -67  25  55  132  71  249  -142  -247  -199  13  -200  -183  -34  -72  -215  164  -39  -23  -17  246  -102  81  -135  -134  111  -206  -12  220  19  3  203  -92  31  98  199  125  152  -136  -109  -201  83  -167  -20  -57  -161  -131  154  241  -5  16  188  121  6  -10  101  114  -128  -205  -82  -242  -179  66  97  207  229  27  131  -54  -156  -27  62  -202  -108  240  9  30  -19  123  108  -69  -157  -43  -137  24  -93  -159  110  -149  148  32  194  -99  -203  -83  172  -204  -147  23  -38  -71  -106  133  -49  138  -11  -207  182  193  42  228  -246  -190  -165  14  -22  -112  160  2  -84  113  51  -163  89  120  -52  109  -218  -168  230  -40  -182  -53  146  139  -33  -127  61  -220  117  -235  -37  -160  -169  158  -68  201  -245  88  56  136  -101  219  200  54  26  -77  36  178  1  130  -187  -8  -1  -30  232  -162  -98  -132  -195  91  -97  -75  165  -172  127  209  -85  208  29  -230  195  -221  210  12  105  141  33  218  237  -224  100  -61  122  -94  -174  184  8  233  5  18  15  143  238  166  -241  -189  73  -104  -141  44  149  -56  -213  -28  206  102  137  191  20  -233  50  -244  -63  -6  -26  244  147  -2  82  64  28  169  -226  -18  226  204  40  140  52  215  177  -125  46  80  -9  -239  250  -42  183  -36  37  170  248  41  180  212  -186  -14  43  77  -50  45  99  -29  -113  22  223  -116  21  -91  -110  68  -222  -66  -15  -209  216  49  -44  -122  -80  196  235  -248  96  103  -166  -148  94  161  -144  157  104  185  38  -114  70  86  -140  -250  153  -74  75  156  -59  39  -171  35  74  -123  -170  197  -96  -25  76  -47  134  106  -107  87  -115  -46  -211  -145  -249  107  145  -208  4  -243  -133  -100  227  116  -126  -188  -70  -216  34  -150  -60  -234  65  -173  189  90 | wc -l
./push_swap -21  -234  -10  148  248  190  -244  -157  -88  -243  78  103  -57  200  231  -208  234  74  -179  -242  33  -82  -152  -202  -73  -93  195  -95  -130  69  53  177  -48  42  -162  -40  102  -99  210  -164  157  -87  45  99  199  151  80  -135  -216  109  142  -248  184  -54  153  -66  228  -217  -59  -174  113  64  -247  83  52  -185  -16  156  -22  1  73  -176  166  155  173  218  -160  59  -228  37  -122  4  29  -86  -209  85  -200  -24  -206  -227  186  211  -132  213  -166  244  -193  -175  -196  194  60  82  -141  -233  -96  90  -221  178  110  -117  -133  24  -119  128  -150  202  56  -230  149  54  63  168  -181  132  -102  6  -215  -177  -41  61  -144  135  125  -111  -123  138  221  50  101  51  172  40  242  -239  -33  -149  -35  158  -4  89  -112  225  241  187  -81  41  -178  114  -211  57  71  223  35  -203  -168  188  160  19  205  -27  -101  -190  25  -197  -74  -5  -100  130  -38  -180  246  123  -34  -83  36  -14  15  -76  13  66  0  -237  -225  -47  -6  18  124  -201  22  81  165  12  150  95  -89  -26  -173  111  -55  -121  -18  -161  -189  -36  107  -52  203  249  176  -136  162  -192  140  -68  26  -224  127  235  -118  192  -62  174  -23  -195  -110  -113  129  94  -72  -25  133  -11  -159  -182  -187  -142  170  196  154  214  -137  -92  -191  14  112  -120  -114  -245  -240  245  -108  180  220  -219  -17  75  193  183  -51  97  232  -138  17  137  68  -2  -126  10  250  23  239  144  -204  -103  -91  -171  -155  233  79  -46  3  116  -212  120  -231  230  119  -31  -220  117  -60  -146  -30  49  2  46  121  -75  -246  175  -106  20  -151  -3  100  -49  11  -85  122  -8  -98  -32  16  198  212  197  217  -45  -134  -249  65  43  70  -156  227  98  -232  38  -238  -205  -13  -107  -128  -194  219  243  224  55  -183  141  58  -199  -250  -97  209  -140  93  -125  -214  -104  -124  -90  236  104  -109  48  206  -186  34  -65  163  -115  77  -198  -163  -170  -77  -223  -172  27  226  -19  -69  96  -43  204  -84  30  189  -235  -53  8  -131  -9  -222  -39  159  222  47  -154  -127  -20  167  39  9  161  32  -78  216  -61  44  -1  -241  31  -143  -158  -129  -44  169  237  146  -12  182  118  -71  -169  -50  5  -7  -105  -15  143  139  72  87  191  115  92  -37  238  -213  86  -42  -116  179  91  -145  84  -210  207  -147  181  -28  105  -207  7  21  108  -139  -80  -29  -56  106  147  -226  -236  171  -63  76  247  201  208  -153  164  -79  145  -218  131  -70  -167  -67  67  -94  -165  -229  240  185  -188  215  136  152  28  -184  229  88  126  -64  62  -58  -148 | wc -l
./push_swap 21  148  213  72  39  -83  3  -7  -60  -34  59  -24  -30  26  -93  -43  -4  -37  -95  -242  -28  136  -14  -67  -144  135  -243  -152  20  9  98  -196  30  211  -66  170  13  149  239  -239  68  154  -102  35  -218  250  214  117  -210  73  223  -128  67  206  249  -217  113  -87  -10  58  12  -124  131  28  60  14  -27  -148  49  245  153  124  163  -92  -77  -17  -230  -142  -227  -151  -134  -173  -123  29  -100  36  93  224  -171  244  96  84  248  205  -11  66  -88  200  -31  22  -158  101  201  -214  -130  -81  34  193  122  -97  226  -226  -42  -145  128  190  -121  38  180  -185  -15  33  -107  -84  183  -176  118  -3  -12  -126  -47  -215  -200  -248  242  189  -55  53  41  196  125  227  -231  -63  -222  69  -68  240  191  -204  -20  150  -80  -85  48  -13  -98  -167  -132  181  -174  91  4  126  164  207  -147  75  204  -108  208  -56  1  -220  142  -46  -228  -159  -201  92  -33  23  15  229  -219  -182  -205  -179  112  -146  -112  -164  -207  210  219  76  -38  -143  217  173  -51  -21  89  119  243  -18  171  -19  195  -2  -72  -188  -120  -59  220  11  47  -161  17  -90  -57  62  168  -160  97  198  134  -136  160  -9  -249  44  -115  114  51  -58  61  182  -23  -141  64  80  -149  -235  178  212  105  -177  -75  234  161  116  197  -104  225  146  83  237  137  25  -62  -129  -73  -198  -53  107  -54  -78  -39  -208  141  -233  187  139  -52  102  140  32  -6  -241  -99  -229  46  -183  -163  -221  133  228  -116  6  -101  138  -172  -191  -245  24  99  -127  -209  -225  37  -69  -199  42  188  241  172  -175  -194  90  222  -86  -117  63  103  236  199  -165  -140  57  202  162  -232  158  -238  -157  221  -155  -106  -211  109  -170  185  100  -25  52  -212  184  0  203  -192  192  2  8  -114  -189  27  144  143  218  95  -186  169  132  151  -178  238  -5  -29  -113  246  -70  -36  -65  -166  -50  85  165  82  -154  79  -137  -240  10  176  127  -110  -247  -118  -169  -35  74  145  -246  186  -94  56  50  216  174  177  -76  -103  -203  31  5  -139  -64  71  159  -1  -79  43  123  45  194  -168  155  235  7  -236  120  -16  -234  94  -237  -74  -44  -119  -244  16  19  18  86  -206  -181  -153  -96  54  -202  156  110  -32  -187  40  -133  -135  -131  175  129  -224  -150  167  -91  -40  108  65  147  -190  233  157  -125  -250  -48  166  81  -111  77  -41  121  88  -82  -184  209  130  115  -89  -105  104  106  87  -22  -109  -197  111  55  -216  215  -193  -61  78  70  231  152  -45  -26  -162  -71  232  -213  -156  -122  -195  230  247  -138  -8  -49  179  -180 | wc -l
./push_swap -54  -71  -88  200  217  155  -170  9  -181  -228  -135  -238  -176  53  -208  -116  -92  -56  88  -43  212  178  203  99  -173  225  -151  170  -217  -213  -152  -127  64  -66  169  108  -250  -13  18  -17  59  97  201  172  229  -148  100  -241  90  130  -112  39  -171  -224  -36  152  66  -1  10  -195  162  144  194  175  -120  -122  -34  -218  -150  191  154  47  -102  -161  -78  -118  -7  -86  -60  236  26  -41  190  222  205  -196  120  49  -186  -239  30  189  32  -103  101  93  -38  199  17  185  55  -70  0  -65  -114  23  -233  58  208  -21  102  -167  180  -193  -229  48  107  95  -24  36  -232  57  118  -50  166  69  16  192  -205  -225  40  -220  34  7  -237  124  157  247  -110  121  96  -94  244  160  -156  -215  -248  105  167  210  -83  -96  -236  216  67  -157  -93  148  41  219  -216  106  80  165  104  60  142  146  -136  -162  -111  33  -180  61  -22  145  68  -189  -223  143  103  -203  207  -115  65  127  20  89  117  82  218  206  -204  -140  -134  43  -125  -226  -72  81  -44  35  195  -242  -172  221  114  184  15  131  112  -247  -39  98  77  181  -209  28  -183  -201  125  46  44  -3  56  158  86  -207  171  -31  -131  138  183  -168  51  -20  42  -23  211  -197  -128  -84  19  -16  -147  -214  135  126  -57  -212  -15  -139  249  246  238  -142  -246  153  29  173  -109  -95  84  74  -11  12  -144  -219  163  140  242  -75  -35  -26  -76  -51  213  -53  -48  -58  -178  -211  24  -188  -155  -42  -149  62  -206  228  214  156  -73  -137  -69  -227  -187  71  3  193  -198  -101  168  -174  119  94  -190  -46  248  115  -9  202  147  198  174  2  129  123  -243  -8  -108  -49  -235  -113  22  85  -141  -129  76  -55  188  -104  -240  -199  204  -29  -249  -12  128  -80  -2  -19  -28  113  234  109  -79  224  -106  159  -45  -222  92  -200  -87  -27  63  240  -124  -191  6  -164  45  -184  38  -245  -145  231  21  -160  182  -117  75  -100  223  227  139  179  -61  -177  -179  -192  141  87  -194  151  233  -14  -121  -59  232  72  -68  70  -30  -91  -85  14  25  54  -77  1  226  91  -153  215  161  137  13  -74  209  -146  116  79  250  5  149  -81  -210  -133  73  -40  -126  -130  -175  -231  -154  237  186  50  150  -52  -10  -123  -33  -67  -5  197  11  -82  -89  196  -90  -6  4  -4  -159  239  -25  -221  -119  136  235  134  111  230  -244  -107  -32  122  27  -97  52  220  176  -166  -63  -202  187  8  -182  -132  -234  -37  133  -165  -138  -169  110  132  177  -18  78  -185  -62  -163  -230  241  -105  83  245  37  -99  31  -158  -143  -64  -98  -47  164 | wc -l
./push_swap -178  152  -248  -226  -176  88  -54  -75  18  180  -65  218  143  -175  121  91  -234  213  39  57  56  -61  23  -76  68  219  -231  126  120  -238  201  -143  166  -62  243  182  151  6  30  66  232  -166  237  108  32  -205  51  -137  -131  226  -123  -103  134  -24  35  -73  19  -154  71  165  195  146  239  249  -215  206  171  -121  -210  147  -119  -207  -147  -239  198  -106  79  229  -46  -17  -142  -184  -97  -233  38  208  -69  207  -88  176  11  -9  -204  13  -15  -66  104  -242  -31  -217  190  110  -139  131  89  136  -203  124  193  216  17  172  -36  238  -122  139  133  86  -128  98  -225  -191  -199  -167  -18  -180  111  -23  -20  -98  127  209  205  -177  -153  -115  85  -155  -174  246  49  -43  -241  -150  -96  15  115  -243  168  47  -179  114  116  123  -77  -229  169  -102  158  44  -246  174  199  59  -32  2  -19  46  -80  -173  217  -144  185  -28  -29  65  -200  -68  122  159  90  -237  -27  -227  -130  -37  -120  -216  -145  4  21  211  178  -79  -64  76  119  -170  -34  -168  55  -133  224  -78  37  -22  -192  -40  7  -108  75  -162  -7  -72  -151  -169  -146  138  155  -193  -83  33  113  -172  26  -185  -245  197  -11  -202  74  82  -45  -189  -126  43  -235  27  -214  236  -250  250  -228  -195  -30  101  -201  -6  132  45  215  189  188  107  -71  -26  24  -57  -89  93  48  -221  -211  -55  154  210  -48  -149  -249  -74  -136  -63  117  194  -2  -218  -87  -165  153  -181  -134  145  -219  95  -182  149  70  -95  186  -3  -163  36  25  150  -51  242  112  142  94  -197  58  50  -240  -107  40  -212  -112  5  -140  -135  12  183  -90  184  -4  42  -244  148  -58  -161  -59  34  -84  -232  -8  -16  -25  102  -1  163  203  -44  -56  -190  -187  -42  204  9  128  -222  -5  137  69  -159  -113  -194  83  14  -33  -92  -13  87  62  -183  -141  80  118  -117  234  -105  -152  135  -10  223  -164  212  67  1  245  -100  10  96  -104  221  31  -206  -14  141  29  -223  -111  -52  248  61  222  -230  77  100  -60  156  -49  227  177  92  0  -12  -85  106  140  -70  -91  162  241  -148  214  22  -236  81  228  244  -118  -160  -156  220  192  -41  -132  -188  -116  -94  -50  -53  8  144  78  -114  181  105  225  63  -224  233  187  -101  109  -213  -158  179  103  -157  247  -129  160  -247  130  -110  167  202  28  173  125  -209  54  52  41  -171  -38  -124  53  60  -81  191  157  -39  -198  84  -125  -127  73  -208  16  196  240  129  -86  -196  -109  -99  -220  161  -82  20  -186  170  231  -21  3  -35  175  -47  64  235  164  97  72  99  200  -67  -93  230 | wc -l
./push_swap -141  -109  -121  105  -150  82  -94  -241  90  -225  246  -3  147  -42  188  -53  87  103  93  233  -234  -78  -6  182  49  167  168  -66  223  40  150  146  -201  215  124  -204  -41  138  -11  183  133  -116  35  232  -249  30  113  72  -183  184  -49  -28  171  -29  236  -119  -215  -127  -167  45  -194  56  130  -205  -101  235  -22  91  -10  174  95  -77  -102  -75  -23  -137  186  8  25  115  -143  73  112  -60  240  -237  248  206  59  -224  -227  -92  154  207  -180  222  -223  -82  -163  60  -124  116  -131  -99  16  -199  160  44  -44  92  -155  -113  -19  57  217  48  -98  -122  -130  149  134  -59  -208  -126  193  -70  -176  81  -12  -129  68  39  31  127  128  101  -57  -81  214  202  -64  1  -162  34  79  -185  -106  122  -226  -18  195  53  180  139  -233  -179  -80  249  -34  -46  -120  -5  109  153  78  22  -79  -228  -209  -190  -27  54  -24  129  83  -43  226  156  -186  12  -33  -61  94  -202  225  -177  135  187  -230  123  209  -123  -231  -112  33  -139  -1  24  -149  -105  -210  -236  155  -178  237  -83  88  -117  148  -229  66  -96  -238  227  108  -20  64  228  234  2  -31  192  28  -188  -219  -175  132  21  86  -16  11  -86  -40  -250  159  -193  -136  -142  -84  172  61  -148  80  98  166  -89  -32  29  74  -71  9  -165  -73  63  -169  13  -48  -65  -248  -245  242  125  224  -108  -239  -15  17  -138  143  -97  -51  157  -47  169  179  -220  75  162  -214  199  245  41  -222  -235  189  -8  121  -145  190  -125  100  -181  210  32  243  -207  136  -198  -132  -217  36  7  201  -69  -21  161  -91  158  -104  55  177  -218  213  165  -95  117  43  -30  239  196  -100  -7  -157  221  -13  -166  230  205  -174  62  -212  -4  47  145  27  -55  -154  4  -200  204  69  -103  -158  -187  -244  -191  -246  10  14  191  -76  -159  -170  170  38  -114  -213  -156  77  -85  107  -189  -221  244  220  5  -232  -88  -171  203  -184  65  152  -111  164  -146  18  -54  -2  19  -153  -90  200  231  -161  176  -134  -164  120  238  -195  26  -128  212  197  104  -63  58  181  -67  118  50  -168  -93  96  76  -35  208  -242  -196  20  46  67  144  -216  -240  -17  -36  -144  241  131  198  -192  -68  -45  114  89  163  185  -182  -173  -197  247  137  173  97  -211  178  -62  0  -14  -203  -74  140  -140  52  -115  119  70  15  99  -50  -39  110  -72  -243  -37  -172  -38  6  106  126  250  142  -9  218  219  -56  -133  102  229  216  23  -26  151  194  -206  211  -135  -110  51  84  -107  -147  -152  -87  42  -25  85  141  -52  3  -118  71  -151  -160  -58  111  -247  175 | wc -l

echo "Checker"
echo "Checker duplicate values"
./checker 1 1
./checker 12 12
./checker -1 -1
./checker 2147483647 2147483647
./checker -2147483648 -2147483648
./checker 3 1 3
./checker -1 2 3 4 -1
./checker 1 23 3 7 5 2 3 5 4 87 9 87 25 6 298 -7 963 2323 47 45 12 12 -7 54 6 34

echo "checker Wrongs values"
./checker -1-1
./checker a
./checker 1a
./checker 1 2 z 3
./checker 1 2 3z 4
./checker +1
./checker --1
./checker 2147483648
./checker -2147483649
./checker 1 2 3 -7-8 4
./checker @1 2
./checker 214l
./checker "1 \2"

echo "Checker some tests"
./checker 

echo "Checker errors, must display Error \ n"
echo "s" | ./checker 2 1 3
echo "rrrr" | ./checker 2 1 3
echo "rb rb rrb rz" | ./checker 2 1 3
echo " rb" | ./checker 2 1 3
echo "  rb" | ./checker 2 1 3
echo "rb " | ./checker 2 1 3
echo "rb  " | ./checker 2 1 3
echo "r b  " | ./checker 2 1 3
echo " rb " | ./checker 2 1 3
echo "  rb  " | ./checker 2 1 3
echo "sa pb rrr" | ./checker 0 9 1 8 2 7 3 6 4 5

echo "End of Checker error"
echo "Test KO, must display KO \ n"
echo "sa\npb\nrrr" | valgrind ./checker 0 9 1 8 2 7 3 6 4 5
echo "sa\npb\nrrr" | valgrind ./checker 0 9 1 8 2 7 3 6 4 5
echo "pb\n" | valgrind ./checker 2 1 3
echo "pb\npb\npa\n" | valgrind ./checker 2 1 3

echo "Checker should display OK"
./push_swap 2 1 0 | ./checker 2 1 0
./push_swap 2 1 0 | ./checker 2 1 0
./push_swap 50 7 1 | ./checker 50 7 1
./push_swap 50 -7 1 | ./checker 50 -1 1
./push_swap 2147483647 1 2 | ./checker 2147483647 1 2

ARG="2 1 5 4 6"; ./push_swap $ARG| ./checker $ARG
ARG="-3 4 -2 0 -1"; ./push_swap $ARG | ./checker $ARG
ARG="-21 46 -44 34 -14"; ./push_swap $ARG | ./checker $ARG
ARG="5 34 -5 8 39"; ./push_swap $ARG | ./checker $ARG
ARG="2147483647 34 -5 8 -2147483648"; ./push_swap $ARG | ./checker $ARG
ARG="-421 -347 -17 -187 -84"; ./push_swap $ARG | ./checker $ARG
ARG="-151 -314 -401 -43 -319"; ./push_swap $ARG | ./checker $ARG
ARG="-108 82 786 992 661"; ./push_swap $ARG | ./checker $ARG
ARG="204 117 51 47 -225 -223 -132 -180 175 120 48 127 -156 -9 -213 -167 -242 67 -133 94 -123 56 26 -230 -93 186 -68 -5 229 -71 128 -220 14 114 163 -92 -175 228 208 -169 -153 -211 174 169 -91 -224 -239 -250 20 6 -145 144 -117 -89 -136 -66 59 86 148 -32 -148 237 -119 235 24 63 -244 42 74 -7 -120 -59 -155 -102 38 81 162 -232 76 95 -149 130 -199 -201 172 25 11 -165 151 232 -33 -197 147 73 72 -45 226 -222 90 -237"; ./push_swap $ARG | ./checker $ARG
ARG="178 11 -204 -52 -44 -2 68 -137 -81 147 -193 -113 230 114 140 5 108 2 244 -27 126 180 -70 -178 -153 -47 -187 249 34 -226 -93 209 -120 61 -208 25 -121 94 152 13 48 227 -28 238 142 -156 -104 -217 50 -29 -169 217 -8 -225 -124 143 186 -150 192 240 -119 -33 24 37 66 151 84 -196 -174 175 -102 -155 -132 38 21 86 -127 174 -114 191 -181 128 90 -173 -31 188 -84 207 100 75 71 -192 231 -83 97 106 -249 -198 -115 101 -190 118 -205 10 -88 -227 26 -223 -216 -87 228 -108 -40 232 176 -22 7 -3 -122 62 -18 -230 113 -159 -195 -123 165 138 -98 35 245 -54 233 -75 36 -140 215 -32 130 -166 -238 20 63 -67 76 -51 219 213 -4 -236 -206 -143 -163 194 199 -179 -234 161 235 -142 -147 -69 103 -213 -229 -78 -218 148 -184 125 17 -62 -199 -194 123 247 144 -17 190 -160 -59 171 225 -212 167 -63 -165 122 -46 -65 237 -176 127 43 -34 -224 32 -116 -80 -10 4 -148 -248 80 -133 33 19 -152 236 49 102 51 -77 150 -131 179 95 234 189 -118 12 92 -200 -79 67 166 -221 -215 -182 39 -103 210 -94 -50 -168 -14  -25 -92 18 164 -186 85 163 -9 -164 -101 246 -58 -180 -57 -5 -128 -151 73 154 56 55 104 -13 135 45 -231 60 -157 47 -1 -146 -107 -66 193 82 9 173 183 88 121 -191 -61 155 -19 22 109 -211 146 -26 -16 169 -35 -210 99 241 -240 -171 -135 -144 187 -36 -183 -73 46 218 81 -111 -220 79 72 139 3 -56 211 -219 1 70 214 -241 226 -109 41 -41 29 -167 16 58 28 141 242 203 -202 -222 -12 -100 105 243 149 98 124 162 129 223 -85 -138 54 -110 -237 136 -233 87 -95 160 -170 -161 40 -158 -96 157 -129 -244 -235 195 172 27 -72 137 248 116 -15 205 64 117 77 -30 -175 -201 57 145 -43 -49 -53 -99 -126 -90 115 -149 153 -239 -188 -232 -246 -247 197 0 -20 120 131 158 -38 -134 -60 15 8 220 -89 206  159 134 133 -82 184 42 -71 202 -64 -42 -141 65 -106 -48 229  -197 208 83 96 110 -145 221 156 -86 93 -11 31 250 181 182 -250 23 -7 -172 -136 -39 -68 -245 -24 -6 185 44 196 -185 -45 14 59 -97 -105 78 91 216 -117 52 222 74 -55 112 -243 224 69 201 -37 6 -162 -189 239 -154 119 53 132 -74 -76 -125 -130 170 -91 -209 -203 168 107 -23 212 89 -214 204 -112 -177 -228 -21 -139 111 -242 200 -207 177 198"; ./push_swap $ARG | ./checker $ARG
