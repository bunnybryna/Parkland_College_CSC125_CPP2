#ifndef _HTMLFORM_H_
#define _HTMLFORM_H_

#include <vector>
#include <string>

#include "namevaluepair.h"

using namespace std;

class HTMLForm
{
    public:
    void debug();
    HTMLForm();

    private:
    vector<NameValuePair> m_FormData;
    string m_QueryString;
};
#endif
