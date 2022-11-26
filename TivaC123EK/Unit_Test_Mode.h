/*
 * Unit_Test_Mode.h
 * This file determines whether to run the actual Project or the unit tests
 * for the Project by defining or undefining "Unit_Test_Mode".
 * Defining "Unit_Test_Mode" makes the access specifiers public, regardless
 * whether it is "private" or "protected" when you include this .h file
 * into your project. This makes it possible to conduct tests on
 * non-public functions which otherwise would be inaccessible to the
 * unit test code.
 *
 *  Created on: 21 Jul 2021
 *      Author: John Chee
 */

#ifndef UNIT_TEST_MODE_H_
#define UNIT_TEST_MODE_H_

// ***** User choice: uncomment next line for unit-testing *****
#define Unit_Test_Mode
//#undef Unit_Test_Mode
// *****---------------------------------------------------*****


//--- unit-testing mode sets all access specifier to "public" -------
#ifdef Unit_Test_Mode
#define private     public
#define protected   public
#endif
//-------------------------------------------------------------------


#endif /* UNIT_TEST_MODE_H_ */
