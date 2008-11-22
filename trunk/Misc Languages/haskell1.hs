
--Given the three constants of a quadratic equation, it returns the pair of roots.

myquad a b c  |  determin < 0    = error "Roots are complex"
                        |  determin == 0  = [ - b / ( 2 * a ) ]
                        |  determin > 0    = [ - b / ( 2 * a ) + rad1 / ( 2 * a ) ,
                                                         - b / ( 2 * a ) -  rad1 / ( 2 * a ) ]
                           where
                           determin = b * b - 4 * a * c
                           rad1 = sqrt  determin