##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=DecompileClsCL
ConfigurationName      :=Release
WorkspacePath          := "G:\MyDocument\CodeLite\DecompileClsCL"
ProjectPath            := "G:\MyDocument\CodeLite\DecompileClsCL"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=fzq
Date                   :=2013/3/1
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
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
ObjectsFileList        :="DecompileClsCL.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O3 -Wall -fexec-charset=GBK $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/AppStart$(ObjectSuffix) $(IntermediateDirectory)/ConstValuesConst$(ObjectSuffix) $(IntermediateDirectory)/FileUt$(ObjectSuffix) $(IntermediateDirectory)/GlobalValues$(ObjectSuffix) $(IntermediateDirectory)/Param$(ObjectSuffix) $(IntermediateDirectory)/StringUt$(ObjectSuffix) 

Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/AppStart$(ObjectSuffix): AppStart.c $(IntermediateDirectory)/AppStart$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/MyDocument/CodeLite/DecompileClsCL/AppStart.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AppStart$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AppStart$(DependSuffix): AppStart.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AppStart$(ObjectSuffix) -MF$(IntermediateDirectory)/AppStart$(DependSuffix) -MM "AppStart.c"

$(IntermediateDirectory)/AppStart$(PreprocessSuffix): AppStart.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AppStart$(PreprocessSuffix) "AppStart.c"

$(IntermediateDirectory)/ConstValuesConst$(ObjectSuffix): ConstValuesConst.c $(IntermediateDirectory)/ConstValuesConst$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/MyDocument/CodeLite/DecompileClsCL/ConstValuesConst.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConstValuesConst$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConstValuesConst$(DependSuffix): ConstValuesConst.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConstValuesConst$(ObjectSuffix) -MF$(IntermediateDirectory)/ConstValuesConst$(DependSuffix) -MM "ConstValuesConst.c"

$(IntermediateDirectory)/ConstValuesConst$(PreprocessSuffix): ConstValuesConst.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConstValuesConst$(PreprocessSuffix) "ConstValuesConst.c"

$(IntermediateDirectory)/FileUt$(ObjectSuffix): FileUt.c $(IntermediateDirectory)/FileUt$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/MyDocument/CodeLite/DecompileClsCL/FileUt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileUt$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileUt$(DependSuffix): FileUt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileUt$(ObjectSuffix) -MF$(IntermediateDirectory)/FileUt$(DependSuffix) -MM "FileUt.c"

$(IntermediateDirectory)/FileUt$(PreprocessSuffix): FileUt.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileUt$(PreprocessSuffix) "FileUt.c"

$(IntermediateDirectory)/GlobalValues$(ObjectSuffix): GlobalValues.c $(IntermediateDirectory)/GlobalValues$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/MyDocument/CodeLite/DecompileClsCL/GlobalValues.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GlobalValues$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GlobalValues$(DependSuffix): GlobalValues.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GlobalValues$(ObjectSuffix) -MF$(IntermediateDirectory)/GlobalValues$(DependSuffix) -MM "GlobalValues.c"

$(IntermediateDirectory)/GlobalValues$(PreprocessSuffix): GlobalValues.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GlobalValues$(PreprocessSuffix) "GlobalValues.c"

$(IntermediateDirectory)/Param$(ObjectSuffix): Param.c $(IntermediateDirectory)/Param$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/MyDocument/CodeLite/DecompileClsCL/Param.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Param$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Param$(DependSuffix): Param.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Param$(ObjectSuffix) -MF$(IntermediateDirectory)/Param$(DependSuffix) -MM "Param.c"

$(IntermediateDirectory)/Param$(PreprocessSuffix): Param.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Param$(PreprocessSuffix) "Param.c"

$(IntermediateDirectory)/StringUt$(ObjectSuffix): StringUt.c $(IntermediateDirectory)/StringUt$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/MyDocument/CodeLite/DecompileClsCL/StringUt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StringUt$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StringUt$(DependSuffix): StringUt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/StringUt$(ObjectSuffix) -MF$(IntermediateDirectory)/StringUt$(DependSuffix) -MM "StringUt.c"

$(IntermediateDirectory)/StringUt$(PreprocessSuffix): StringUt.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StringUt$(PreprocessSuffix) "StringUt.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/AppStart$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AppStart$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AppStart$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ConstValuesConst$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ConstValuesConst$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ConstValuesConst$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/FileUt$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/FileUt$(DependSuffix)
	$(RM) $(IntermediateDirectory)/FileUt$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/GlobalValues$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/GlobalValues$(DependSuffix)
	$(RM) $(IntermediateDirectory)/GlobalValues$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Param$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Param$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Param$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/StringUt$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/StringUt$(DependSuffix)
	$(RM) $(IntermediateDirectory)/StringUt$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-release/DecompileClsCL"


