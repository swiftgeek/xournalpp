/*
 * Xournal++
 *
 * Handles the layout of the pages within a Xournal document
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "widgets/Scrollbar.h" // because of extends ScrollbarListener
#include <XournalType.h>

#include <gtk/gtk.h>

class PageView;
class XournalView;

class Layout : public ScrollbarListener
{
public:
	Layout(XournalView* view);
	virtual ~Layout();

public:
	void setSize(int widgetWidth, int widgetHeight);
	void scrollRelativ(int x, int y);
	bool scrollEvent(GdkEventScroll* event);
	void ensureRectIsVisible(int x, int y, int width, int height);
	double getVisiblePageTop(size_t page);
	double getDisplayHeight();

	void layoutPages();

	GtkWidget* getScrollbarVertical();
	GtkWidget* getScrollbarHorizontal();

	void setLayoutSize(int width, int height);

	void updateRepaintWidget();

	virtual void scrolled(Scrollbar* scrollbar);

	void checkSelectedPage();

private:
	XOJ_TYPE_ATTRIB;

	XournalView* view;

	Scrollbar* scrollVertical;
	Scrollbar* scrollHorizontal;

	/**
	 * Outer border of the complete layout
	 */
	int marginTop;
	int marginLeft;
	int marginRight;
	int marginBottom;

	/**
	 * The last width of the widget
	 */
	int lastWidgetWidth;

	/**
	 * The width and height of all our pages
	 */
	int layoutWidth;
	int layoutHeight;
};
