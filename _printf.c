nclude <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "main.h"

/**
 *  * unsigned_number_to_string - converts unsigned number to string
 *   * @number: first argument
 *    * @base: second argument
 *     * @buffer: third argument
 *      *
 *       * Return: void
 *        */
 
void unsigned_number_to_string(uint64_t number, int base, char *buffer)
{
	    if (number == 0)
		        {
				        *buffer++ = '0';
					        *buffer = 0;
						        return;
							    }

	        char buf[65];
		    int i;

		        for (i = 0; i < 65; i++)
				    {
					            buf[i] = 0;
						        }

			    int cur = 0;

			        while (number)
					    {
						            int digit = number % base;

							            if (digit >= 10)
									            {
											                buf[cur++] = 'a' + (digit - 10);

													        }
								            else
										            {
												                buf[cur++] = '0' + digit;
														        }
									            number /= base;
										        }
				        for (i = cur - 1; i != 0; i--)
						            *buffer++ = buf[i];
					        *buffer++ = buf[0];
						        *buffer = 0;
}

/**
 *  * number_to_string - converts number to string
 *   * @number: first argument
 *    * @base: second argument
 *     * @buffer: third argument
 *      *
 *       * Return: void
 *        */

    void number_to_string(int64_t number, int base, char *buffer)
	    {
		            if (number < 0)
				            {
						                *buffer++ = '-';
								            number = -number;
									            }
			            unsigned_number_to_string(number, base, buffer);
				        }
    


/* state */
/* 0 is regular */
/* 1 is escape */

/**
 *  * v_printf - performs the print function in a formatted way
 *   * @fmt: first argument, the format
 *    * @args: second argument, the list of argument variables
 *     *
 *      * Return: void
 *       */

void v_printf(const char *fmt, va_list args)
{
	    int state = 0;
	        int is_long = 0;
		    int can_reset = 1;
		        char number_buffer[65];

			    while (*fmt)
				        {
						        if (state == 0)
								        {
										            if (*fmt == '%')
												                {
															                state = 1;
																	            }
											                else
														            {
																                    putchar(*fmt);
																		                }
													        }
							        else if (state == 1)
									        {
											            switch (*fmt)
													                {
																                case 'c':{
																				                     char ch = va_arg(args, int);
																						                         putchar(ch);
																									                     break;
																											                     }
																			                 case 's':
																			                 {
																						                     const char *s = va_arg(args, const char *);

																								                         while (*s)
																												                     {
																															                             putchar(*s++);
																																		                         }
																											                     
																											                     break;
																													                     }
																					                 case 'l':
																					                 {
																								                     is_long = 1;
																										                         can_reset = 0;
																													                     break;
																															                     }
																							                 case 'd':
																							 				case 'i':
																							 					{
																													                    int64_t n;
																															                        if (is_long == 1)
																																			                    {
																																						                            n = va_arg(args, long);
																																									                        }
																																		                    else
																																					                        {
																																									                        n = va_arg(args, int);
																																												                    }              
																																				                        

																																				                        number_to_string(n, 10, number_buffer);
																																							                    int i;

																																									                        for (i = 0; number_buffer[i]; i++)
																																													                    {
																																																                            putchar(number_buffer[i]);
																																																			                        }
																																												                    break;
																																														                    }
																												                case 'u':{
																																                     uint64_t n;
																																		                         if (is_long == 1)
																																						                     {
																																									                             n = va_arg(args, unsigned long);
																																												                         }
																																					                     else
																																								                         {
																																												                         n = va_arg(args, unsigned int);
																																															                     }              
																																							                         

																																							                         number_to_string((uint64_t) n, 10, number_buffer);
																																										                     int i;

																																												                         for (i = 0; number_buffer[i]; i++)
																																																                     {
																																																			                             putchar(number_buffer[i]);
																																																						                         }
																																															                     break;
																																																	                     }
																															                 case 'x':
																															 				case 'X':
																															 					{
																																					                    int64_t n;
																																							                        if (is_long == 1)
																																											                    {
																																														                             n = va_arg(args, unsigned long);
																																																	                         }
																																										                    else
																																													                        {
																																																	                         n = va_arg(args, unsigned int);
																																																				                     }  

																																												                        unsigned_number_to_string(n, 16, number_buffer);
																																															                    int i;

																																																	                        for (i = 0; number_buffer[i]; i++)
																																																					                    {
																																																								                            putchar(number_buffer[i]);
																																																											                        }
																																																				                    break;
																																																						                    }
																																				                case 'o':{
																																								                     int64_t n;
																																										                         if (is_long == 1)
																																														                     {
																																																	                              n = va_arg(args, unsigned long);
																																																				                          }
																																													                     else
																																																                         {
																																																				                          n = va_arg(args, unsigned int);
																																																							                      }  

																																															                         unsigned_number_to_string(n, 8, number_buffer);
																																																		                     int i;

																																																				                         for (i = 0; number_buffer[i]; i++)
																																																								                     {
																																																											                             putchar(number_buffer[i]);
																																																														                         }
																																																							                     break;
																																																									                     }
																																							                 case 'p':{
																																											                      /*putchar('0'); */
																																											                      /*putchar('x'); */

																																											                      void *n = va_arg(args, void *);

																																													                          unsigned_number_to_string((uint64_t) n, 16, number_buffer);
																																																                      int i;

																																																		                          for (i = 0; number_buffer[i]; i++)
																																																						                      {
																																																									                              putchar(number_buffer[i]);
																																																												                          }
																																																					                      break;
																																																							                      }
																																										                  default:
																																										                  {
																																													                  	putchar(*fmt);
																																																                }
																																												              }
												                if (can_reset == 1)
															            {
																	                    state = 0;
																			                    is_long = 0;
																					                }
														            else
																                {
																			                can_reset = 1;
																					            }
															            }
								        fmt++;
									    }
}

/**
 *  * _printf - the real printing function
 *   * @fmt: first argument
 *    * @...: ellipses
 *     *
 *      * Return: void
 *       */

__attribute__ ((format (printf, 1, 2))) int _printf(const char *fmt, ...)
{
	        va_list args;
		        va_start(args, fmt);

			        v_printf(fmt, args);   

				        va_end(args);
					        
					        int i = 0;
						        int j = 0;
							        while (*fmt++)
									        {
											        	if (*fmt == '%')
																	{
																			        	if(*fmt == *(fmt+1))
																							        	{
																											        		j++;
																															        	}
																					        	}
													        	else
																        	{
																				        	i++;
																							        }
															        }
								        if (j == 0)
										        	return (i);
									       	else
											       		return (i+j);
										        
}
