##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=POJ
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/eards/Desktop/SoftwareLabTwo
ProjectPath            :=C:/Users/eards/Desktop/SoftwareLabTwo/POJ
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=eards
Date                   :=24/09/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="POJ.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:\Users\eards\Desktop\SoftwareLabTwo\doctest\doctest $(IncludeSwitch)C:\Users\eards\Desktop\sfml\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Users\eards\Desktop\sfml\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe --std=gnu++14
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Playership.cpp$(ObjectSuffix) $(IntermediateDirectory)/Project_Main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ScreenRender.cpp$(ObjectSuffix) $(IntermediateDirectory)/Asteroid.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp $(IntermediateDirectory)/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/eards/Desktop/SoftwareLabTwo/POJ/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/Playership.cpp$(ObjectSuffix): Playership.cpp $(IntermediateDirectory)/Playership.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/eards/Desktop/SoftwareLabTwo/POJ/Playership.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Playership.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Playership.cpp$(DependSuffix): Playership.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Playership.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Playership.cpp$(DependSuffix) -MM Playership.cpp

$(IntermediateDirectory)/Playership.cpp$(PreprocessSuffix): Playership.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Playership.cpp$(PreprocessSuffix) Playership.cpp

$(IntermediateDirectory)/Project_Main.cpp$(ObjectSuffix): Project_Main.cpp $(IntermediateDirectory)/Project_Main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/eards/Desktop/SoftwareLabTwo/POJ/Project_Main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Project_Main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Project_Main.cpp$(DependSuffix): Project_Main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Project_Main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Project_Main.cpp$(DependSuffix) -MM Project_Main.cpp

$(IntermediateDirectory)/Project_Main.cpp$(PreprocessSuffix): Project_Main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Project_Main.cpp$(PreprocessSuffix) Project_Main.cpp

$(IntermediateDirectory)/ScreenRender.cpp$(ObjectSuffix): ScreenRender.cpp $(IntermediateDirectory)/ScreenRender.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/eards/Desktop/SoftwareLabTwo/POJ/ScreenRender.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ScreenRender.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ScreenRender.cpp$(DependSuffix): ScreenRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ScreenRender.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ScreenRender.cpp$(DependSuffix) -MM ScreenRender.cpp

$(IntermediateDirectory)/ScreenRender.cpp$(PreprocessSuffix): ScreenRender.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ScreenRender.cpp$(PreprocessSuffix) ScreenRender.cpp

$(IntermediateDirectory)/Asteroid.cpp$(ObjectSuffix): Asteroid.cpp $(IntermediateDirectory)/Asteroid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/eards/Desktop/SoftwareLabTwo/POJ/Asteroid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Asteroid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Asteroid.cpp$(DependSuffix): Asteroid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Asteroid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Asteroid.cpp$(DependSuffix) -MM Asteroid.cpp

$(IntermediateDirectory)/Asteroid.cpp$(PreprocessSuffix): Asteroid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Asteroid.cpp$(PreprocessSuffix) Asteroid.cpp

$(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix): CollisionHandler.cpp $(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/eards/Desktop/SoftwareLabTwo/POJ/CollisionHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix): CollisionHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix) -MM CollisionHandler.cpp

$(IntermediateDirectory)/CollisionHandler.cpp$(PreprocessSuffix): CollisionHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionHandler.cpp$(PreprocessSuffix) CollisionHandler.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


