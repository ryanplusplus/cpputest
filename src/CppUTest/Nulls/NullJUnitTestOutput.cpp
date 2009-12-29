/*
 * Copyright (c) 2007, Michael Feathers, James Grenning and Bas Vodde
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "CppUTest/TestHarness.h"
#include "CppUTest/JUnitTestOutput.h"
#include "CppUTest/TestResult.h"
#include "CppUTest/Failure.h"

//struct JUnitTestOutputImpl
//{
//
//};
//

JUnitTestOutput::JUnitTestOutput() :
	impl_(0)
{
}

JUnitTestOutput::~JUnitTestOutput()
{
}

void JUnitTestOutput::resetTestGroupResult()
{
}

void JUnitTestOutput::printTestsStarted()
{
}

void JUnitTestOutput::printCurrentGroupStarted(const Utest& test)
{
}

void JUnitTestOutput::printCurrentTestEnded(const TestResult& result)
{
}

void JUnitTestOutput::printTestsEnded(const TestResult& result)
{
}

void JUnitTestOutput::printCurrentGroupEnded(const TestResult& result)
{
}

void JUnitTestOutput::printCurrentTestStarted(const Utest& test)
{
}

void JUnitTestOutput::writeXmlHeader()
{
}

void JUnitTestOutput::writeTestSuiteSummery()
{
}

void JUnitTestOutput::writeProperties()
{
}

void JUnitTestOutput::writeTestCases()
{
}

void JUnitTestOutput::writeFailure(JUnitTestCaseResultNode* node)
{
}

void JUnitTestOutput::writeFileEnding()
{
}

void JUnitTestOutput::writeTestGroupToFile()
{
}

void JUnitTestOutput::verbose()
{
}

void JUnitTestOutput::print(const char*)
{
}

void JUnitTestOutput::print(long)
{
}

void JUnitTestOutput::print(const Failure& failure)
{
}

void JUnitTestOutput::printTestRun(int number, int total)
{
}

void JUnitTestOutput::flush()
{
}

void JUnitTestOutput::openFileForWrite(const SimpleString& fileName)
{
}

void JUnitTestOutput::writeToFile(const SimpleString& buffer)
{
}

void JUnitTestOutput::closeFile()
{
}
