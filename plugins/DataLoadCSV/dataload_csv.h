#ifndef DATALOAD_CSV_H
#define DATALOAD_CSV_H

#include <QObject>
#include <QtPlugin>
#include "../dataloader_base.h"


class  DataLoadCSV: public QObject, DataLoader
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.icarustechnology.Superplotter.DataLoader" "../dataloader.json")
    Q_INTERFACES(DataLoader)

public:
    DataLoadCSV();
    virtual const std::vector<const char*>& compatibleFileExtensions() const ;

    virtual PlotDataMap readDataFromFile(const std::string& file_name,
                                         std::string &time_index_name  );

    virtual ~DataLoadCSV();

protected:
    int parseHeader(QFile *file, std::vector<std::pair<bool, QString> > &ordered_names);

private:
    std::vector<const char*> _extensions;


};

#endif // DATALOAD_CSV_H
