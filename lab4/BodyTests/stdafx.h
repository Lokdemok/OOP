// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
//#define BOOST_TEST_NO_MAIN 
// подключаем реализацию boost test
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)
#include <boost/algorithm/string/replace.hpp>
#include <boost/test/unit_test.hpp>