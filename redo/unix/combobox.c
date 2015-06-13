// 11 june 2015
#include "uipriv_unix.h"

struct combobox {
	uiCombobox c;
	GtkWidget *widget;
};

uiDefineControlType(uiCombobox, uiTypeCombobox, struct combobox)

static uintptr_t comboboxHandle(uiControl *cc)
{
	struct combobox *c = (struct combobox *) cc;

	return (uintptr_t) (c->widget);
}

static void comboboxAppend(uiCombobox *cc, const char *text)
{
	struct combobox *c = (struct combobox *) cc;

	PUT_CODE_HERE;
}

static uiCombobox *finishNewCombobox(OSTHING OSARG)
{
	struct combobox *c;

	c = (struct combobox *) MAKE_CONTROL_INSTANCE(uiTypeCombobox());

	PUT_CODE_HERE;

	uiControl(c)->Handle = comboboxHandle;

	uiCombobox(c)->Append = comboboxAppend;

	return uiCombobox(c);
}

uiCombobox *uiNewCombobox(void)
{
	return finishNewCombobox(OSARGNONEDITABLE);
}

uiCombobox *uiNewEditableCombobox(void)
{
	return finishNewCombobox(OSARGEDITABLE);
}