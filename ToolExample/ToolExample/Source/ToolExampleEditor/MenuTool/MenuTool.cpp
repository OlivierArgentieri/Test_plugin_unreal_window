#include "MenuTool.h"
#include "ToolExampleEditor/ToolExampleEditor.h"
#define LOCTEXT_NAMESPACE "MenuTool"

class MenuToolCommands : public TCommands<MenuToolCommands>
{
public:
	MenuToolCommands()
	: TCommands<MenuToolCommands>(
		TEXT("MenuTool"), // context name
		FText::FromString("Example Menu tool"), // context name for dipslaying
		NAME_None,
		FEditorStyle::GetStyleSetName() // Icon Style Set
		)
	{}

	virtual void RegisterCommands() override
	{
		UI_COMMAND(MenuCommand1, "Menu command 1", "Test Menu Command 1", EUserInterfaceActionType::Button, FInputGesture());
	}

public:
	TSharedPtr<FUICommandInfo> MenuCommand1;
	
};

void MenuTool::MapCommands()
{
	const auto& _commands = MenuToolCommands::Get();

	CommandList->MapAction
	(
		_commands.MenuCommand1,
		FExecuteAction::CreateSP(this, &MenuTool::MenuCommand1),
		FCanExecuteAction()
	);
}


void MenuTool::OnStartupModule()
{
	CommandList = MakeShareable(new FUICommandList);
	MenuToolCommands::Register();
	MapCommands();
	FToolExampleEditor::Get().AddMenuExtension
	(
		FMenuExtensionDelegate::CreateRaw(this, &MenuTool::MakeMenuEntry),
		FName("Section_1"),
		CommandList
	);
}

void MenuTool::OnShutdownModule()
{
	MenuToolCommands::Unregister();
}

void MenuTool::MakeMenuEntry(FMenuBuilder& _menuBuilder)
{
	_menuBuilder.AddMenuEntry(MenuToolCommands::Get().MenuCommand1);
}

void MenuTool::MenuCommand1()
{
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Enchantier"));
}

#undef LOCTEXT_NAMESPACE