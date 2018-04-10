#ifndef SCRIPTINGENGINE_H
#define SCRIPTINGENGINE_H
#include <memory>
#include <string>
class QString;
class MapClient;

class ScriptingEngine
{
public:
    ScriptingEngine();
    ~ScriptingEngine();
    void registerTypes();
    int loadAndRunFile(const QString &path);
    std::string callFuncWithClientContext(MapClient *client,const char *name,int arg1);
    std::string callFunc(const char *name,int arg1);
    int runScript(const QString &script_contents,const char *script_name="unnamed script");
    int runScript(MapClient *client,const QString &script_contents,const char *script_name="unnamed script");
private:
#ifdef SCRIPTING_ENABLED
    struct ScriptingEnginePrivate;
    std::unique_ptr<ScriptingEnginePrivate> m_private;
#endif
};

#endif // SCRIPTINGENGINE_H