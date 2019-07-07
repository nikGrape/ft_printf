# ft_printf
## reproduce the behavior of the printf function
#### *colors support:*
  
   usage: ft_printf("{red}Hello {eoc}world!") // Hello *will be red*, world *will be white*
1. red
2. bold_red
3. green
4. bold_green
5. yellow
6. bold_yellow
7. blue
8. bold_blue
9. magenta
10. bold_magenta
11. cyan
12. bold_cyan
13. bold_gray
14. black
13. eoc - end of color

#### *send length as a parametr:*

   usage: ft_printf("%0*d", 5, 19); // 00019
