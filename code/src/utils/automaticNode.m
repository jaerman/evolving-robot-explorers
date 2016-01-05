%%
%TODO: don't have a boxes the same size: smallest box size only for the
%nodes which should be removed later. All other boxes can be bigger to
%avoid memory issues
%%
%Set the size of the boxes
sizeX = 0.01; sizeXStr = num2str(sizeX);
sizeH = 0.01; sizeHStr = num2str(sizeH);
sizeY = 0.01; sizeYStr = num2str(sizeY);

size = strcat(['        size ',sizeXStr,' ',sizeHStr,' ',sizeYStr]);

%Calculate the positions
%translations: x,höhe,y
x = 0:sizeX:10*sizeX;
height = 0:sizeH:4*sizeH;
y = 0:sizeY:10*sizeY;
%Actual writing the nodes
fileID = fopen('nodes.txt','w');
for i=1:length(x)
    for j=1:length(height)
        for k=1:length(y)
xStr = num2str(x(i));
heightStr = num2str(height(j));
yStr = num2str(y(k));
translation = strcat(['  translation ',xStr,' ',heightStr,' ',yStr]);
    
fprintf(fileID,'%s \n','DEF ICECRUST Solid {');
fprintf(fileID,'%s \n',translation);
fprintf(fileID,'%s \n','  children [');
fprintf(fileID,'%s \n','    DEF ICE_BOX Shape {');
fprintf(fileID,'%s \n','      appearance Appearance {');
fprintf(fileID,'%s \n','         material Material {');
fprintf(fileID,'%s \n','           diffuseColor 0 0.498039 1');
fprintf(fileID,'%s \n','         }');
fprintf(fileID,'%s \n','         texture ImageTexture {');
fprintf(fileID,'%s \n','           url [');
fprintf(fileID,'%s \n','             "Europa_Ice_Rafts.jpg"');
fprintf(fileID,'%s \n','           ]');
fprintf(fileID,'%s \n','         }');
fprintf(fileID,'%s \n','       }');
fprintf(fileID,'%s \n','       geometry Box {');
fprintf(fileID,'%s \n',size);
fprintf(fileID,'%s \n','      }');
fprintf(fileID,'%s \n','    }');
fprintf(fileID,'%s \n','  ]');
fprintf(fileID,'%s \n','  boundingObject USE ICE_BOX');
fprintf(fileID,'%s \n','}');
        end
    end
end
fclose(fileID);
% % Node Text:
% DEF ICECRUST Solid {
%   translation 0 0 0.1
%   children [
%     DEF ICE_BOX Shape {
%       appearance Appearance {
%         material Material {
%           diffuseColor 0 0.498039 1
%         }
%         texture ImageTexture {
%           url [
%             "Europa_Ice_Rafts.jpg"
%           ]
%         }
%       }
%       geometry Box {
%         size 0.1 0.1 0.1
%       }
%     }
%   ]
%   boundingObject USE ICE_BOX
% }