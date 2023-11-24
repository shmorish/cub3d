/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:37:19 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/24 13:06:37 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define USAGE "Usage: ./cub3D <map.cub>"
#define ONE "                                           "
#define TWO "                                                        \n"
#define THREE "                                       bb"
#define FOUR "bbbbbb                                                    \n"
#define FIVE "        CCCCCCCCCCCCC                  b::"
#define SIX "::::b             333333333333333   DDDDDDDDDDDDD        \n"
#define SEVEN "     CCC::::::::::::C                  b:"
#define EIGHT ":::::b            3:::::::::::::::33 D::::::::::::DDD     \n"
#define NINE "   CC:::::::::::::::C                  b::"
#define TEN "::::b            3::::::33333::::::3D:::::::::::::::DD   \n"
#define ELEVEN "  C:::::CCCCCCCC::::C                   "
#define TWELVE "b:::::b            3333333     3:::::3DDD:::::DDDDD:::::D  \n"
#define THIRTEEN " C:::::C       CCCCCCuuuuuu    uuuuuu   "
#define FOURTEEN "b:::::bbbbbbbbb                3:::::3  D:::::D    D:::::D \n"
#define FIFTEEN "C:::::C              u::::u    u::::u   "
#define SIXTEEN "b::::::::::::::bb              3:::::3  D:::::D     D:::::D\n"
#define SEVENTEEN "C:::::C              u::::u    u::::u   "
#define EIGHTEEN "b::::::::::::::::b     33333333:::::3   D:::::D     D:::::D\n"
#define NINETEEN "C:::::C              u::::u    u::::u   "
#define TW "b:::::bbbbb:::::::b    3:::::::::::3    D:::::D     D:::::D\n"
#define TWONE "C:::::C              u::::u    u::::u   "
#define TWTWO "b:::::b    b::::::b    33333333:::::3   D:::::D     D:::::D\n"
#define TWTHREE " C:::::C       CCCCCCu:::::uuuu:::::u   "
#define TWFOUR "b:::::b     b:::::b            3:::::3  D:::::D    D:::::D \n"
#define TWFIVE "  C:::::CCCCCCCC::::Cu:::::::::::::::uu "
#define TWSIX "b:::::b     b:::::b            3:::::3  D:::::D    D:::::D \n"
#define TWSEVEN "  C:::::CCCCCCCC::::Cu:::::::::::::::u"
#define TWEIGHT "u b:::::bbbbbb::::::b3333333     3:::::3DDD:::::DDDDD:::::D  \n"
#define TWNINE "   CC:::::::::::::::C u:::::::::::::::u b"
#define THIRTY "::::::::::::::::b 3::::::33333::::::3D:::::::::::::::DD   \n"
#define THIRTYONE "     CCC::::::::::::C  uu::::::::uu:::u b"
#define THIRTYTWO ":::::::::::::::b  3:::::::::::::::33 D::::::::::::DDD     \n"
#define THIRTYTHREE "        CCCCCCCCCCCCC    uuuuuuuu  uuuu b"
#define THIRTYFOUR "bbbbbbbbbbbbbbb    333333333333333   DDDDDDDDDDDDD        \n"

int	main(void)
{
	printf("%s%s%s%s%s%s%s%s", ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT);
	printf("%s%s%s%s%s%s", NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN);
	printf("%s%s%s%s%s%s", FIFTEEN, SIXTEEN, SEVENTEEN, EIGHTEEN, NINETEEN, TW);
	printf("%s%s%s%s%s%s", TWONE, TWTWO, TWTHREE, TWFOUR, TWFIVE, TWSIX);
	printf("%s%s%s%s", TWSEVEN, TWEIGHT, TWNINE, THIRTY);
	printf("%s%s%s%s%s", THIRTYONE, THIRTYTWO, THIRTYTHREE, THIRTYFOUR, ONE);
	printf("\n\n");
	printf("%s\n", USAGE);
	return (0);
}
