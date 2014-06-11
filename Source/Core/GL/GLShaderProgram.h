#pragma once

#include <Core/ShaderProgram.h>
#include "GLEW/glew.h"

namespace gcore
{

	class GLShaderProgram : public ShaderProgram
	{
	public:
		GLShaderProgram();
		~GLShaderProgram();

		struct GLLocation : public ShaderProgram::Location
		{
		public:
			GLLocation() :mLocation(-1){}

			GLint GetLocation() const { return mLocation; }
			void SetLocation(GLint location) { mLocation = location; }

		protected:
			GLint mLocation;
		};

		virtual void SetIsActive(bool isActive) override;

		virtual bool SetUniformBool(Location* location, bool b) override;
		virtual bool SetUniformInt(Location* location, int i) override;
		virtual bool SetUniformFloat(Location* location, float f) override;
		virtual bool SetUniformDouble(Location* location, double d) override;

		virtual bool SetUniformIntVector2(Location* location, const gbase::IVector2& ivec2) override;
		virtual bool SetUniformFloatVector2(Location* location, const gbase::Vector2& vec2) override;
		virtual bool SetUniformDoubleVector2(Location* location, const gbase::DVector2&dvec2) override;

		virtual bool SetUniformIntVector3(Location* location, const gbase::IVector3& ivec3) override;
		virtual bool SetUniformFloatVector3(Location* location, const gbase::Vector3& vec3) override;
		virtual bool SetUniformDoubleVector3(Location* location, const gbase::DVector3& dvec3) override;

		virtual bool SetUniformIntVector4(Location* location, const gbase::IVector4& ivec4) override;
		virtual bool SetUniformFloatVector4(Location* location, const gbase::Vector4& vec4) override;
		virtual bool SetUniformDoubleVector4(Location* location, const gbase::DVector4& dvec4) override;

		virtual bool SetUniformFloatMatrix3(Location* location, const gbase::Matrix3& mat3) override;
		virtual bool SetUniformDoubleMatrix3(Location* location, const gbase::DMatrix3& dmat3) override;

		virtual bool SetUniformFloatMatrix4(Location* location, const gbase::Matrix4& mat4) override;
		virtual bool SetUniformDoubleMatrix4(Location* location, const gbase::DMatrix4& dmat4) override;

		virtual Location* GetAttributeLocation(const std::string& name) override;
		virtual Location* GetUniformLocation(const std::string& name) override;

		virtual bool Load() override;

		GLuint GetProgram() const;

	private:
		virtual bool Generate() override;
		virtual void UnLoad() override;
		virtual bool Link();

		GLuint mProgram;
	};
}